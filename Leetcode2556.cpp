class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>> &g) {
        int m = g.size(), n = g[0].size();
        function<bool(int, int)> dfs = [&](int x, int y) -> bool { // 返回能否到达终点
            if (x == m - 1 && y == n - 1) return true;
            g[x][y] = 0; // 直接修改
            return x < m - 1 && g[x + 1][y] && dfs(x + 1, y) ||
                   y < n - 1 && g[x][y + 1] && dfs(x, y + 1);
        };
        return !dfs(0, 0) || !dfs(0, 0);
    }
};
