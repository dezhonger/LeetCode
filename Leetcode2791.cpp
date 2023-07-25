class Solution {
public:
    typedef long long LL;
    long long countPalindromePaths(vector<int>& p, string s) {
        int n = p.size();
        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i++) g[p[i]].push_back(i);
        
        LL ans = 0;
        
        unordered_map<LL, LL> cnt;
        cnt[0] = 1;
        // v:当前枚举的顶点， val: 从root到v的异或值
        function<void(int,int)> dfs = [&](int v, int val) 
        {
            for (auto& y: g[v])
            {
                LL bt = 1 << (s[y] - 'a');
                LL x = val ^ bt;
                // x ^ x = 0
                ans += cnt[x];
                // x ^ (z) = 2^k
                for (int i = 0; i < 26; i++) ans += cnt[x ^ (1 << i)];

                cnt[x]++;
                dfs(y, x);
            }
        };

        dfs(0, 0);
        return ans;
    }
};
