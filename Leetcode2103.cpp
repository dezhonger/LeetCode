class Solution {
public:
    int countPoints(string rings) {
        int res = 0, n = rings.size();
        unordered_map<char, int> mp = {{'R', 0}, {'G', 1}, {'B', 2}};
        vector<int> c(10);
        for (int i = 0; i < n; i += 2)
        {
            int label = rings[i + 1] - '0';
            c[label] |= (1 << mp[rings[i]]);
        }

        for (int x : c) if (x == 7) res++;
        return res;
    }
};
