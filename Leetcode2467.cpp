// https://leetcode.cn/problems/most-profitable-path-in-a-tree/solution/liang-bian-dfs-by-endlesscheng-da7j/
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1, ans = INT_MIN;
        vector<int> g[n], btime(n, n);
        for (auto& e: edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        function<bool(int, int, int)> dfs_b = [&](int node, int fa, int t) -> bool
        {
            if (node == 0) {btime[node] = t; return true;}
            for (int y : g[node]) if (y != fa && dfs_b(y, node, t + 1)) {btime[node] = t; return true;}
            return false;
        };
        dfs_b(bob, -1, 0);

        function<void(int, int, int, int)> dfs_a = [&](int node, int fa, int t, int tot) -> void
        {
            if (t < btime[node]) tot += amount[node];
            else if (t == btime[node]) tot += amount[node] / 2;
            if (g[node].size() == 1 && node != 0) {ans = max(ans, tot); return;}
            for (int y: g[node]) if (y != fa) dfs_a(y, node, t + 1, tot);
        };
        dfs_a(0, -1, 0, 0);

        return ans;
    }
};
