class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建图
        }

        vector<int> vis(n);
        int ans = 0, v, e;
        function<void(int)> dfs = [&](int x) {
            vis[x] = true;
            v++;
            e += g[x].size();
            for (int y: g[x])
                if (!vis[y])
                    dfs(y);
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                v = 0;
                e = 0;
                dfs(i);
                ans += e == v * (v - 1);
            }
        }
        return ans;
    }
};
