class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto x: grid) {
            for (auto y: x) {
                v.push_back(y);
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int t = v[v.size() / 2];
        for (int i = 0; i < v.size(); i++) {
            if ((v[i] - t) % x != 0) return -1;
            ans += abs(v[i] - t) / x;
        }
        return ans;
    }
};
