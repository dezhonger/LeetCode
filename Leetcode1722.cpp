class Solution {
public:
    vector<int> f;
    
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        f = vector<int>(n);
        iota(f.begin(), f.end(), 0);
        for (auto& x: allowedSwaps) {
            f[find(x[0])] = find(x[1]);
        }
        int res = 0;
        vector<vector<int>> v1(n), v2(n);
        for (int i = 0; i < n; i++) {
            int fa = find(i);
            v1[fa].push_back(source[i]);
            v2[fa].push_back(target[i]);
        }
        for (int i = 0; i < n; i++) {
            auto x = v1[i];
            auto y = v2[i];
            unordered_multiset<int> s(y.begin(), y.end());
            for (int z: x) {
                auto it = s.find(z);
                if (it != s.end()) s.erase(it);
                else res++;
            }
        }
        return res;
    }
};
