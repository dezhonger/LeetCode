class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
        vector<int> v(n, false);
        for (auto& e: roads)
        {
            int x = e[0] - 1, y = e[1] - 1, z = e[2];
            g[x].push_back(make_pair(y, z));
            g[y].push_back(make_pair(x, z));
        }

        int ans = INT_MAX;

        function<void(int)> dfs = [&](int node) -> void
        {
            v[node] = true;
            for (auto nxt: g[node])
            {
                ans = min(ans, nxt.second);
                if (v[nxt.first]) continue;
                dfs(nxt.first);
            }
        };

        dfs(0);
        return ans;
    }
};
