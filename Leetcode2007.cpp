class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        if (a.size() % 2 != 0) return vector<int>();
        unordered_map<int, int> ms;
        for (int x: a) ms[x]++;
        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> ans;
        for (int x: a) {
            if ((x != 0 && ms[x] && ms[x * 2]) || (x == 0 && ms[x] >= 2)) {
                ans.push_back(x);
                ms[x]--;
                ms[x * 2]--;
            }
        }

        if (ans.size() == n / 2) return ans;
        return vector<int>();
    }
};
