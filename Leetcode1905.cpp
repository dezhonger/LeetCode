class Solution {
public:
    int n, m;
    vector<vector<int>> g1, g2;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool dfs(int x, int y) {
        g2[x][y] = 3;
        bool f = g1[x][y] == 1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && b >= 0 && a < n && b < m && g2[a][b] == 1) {
                f &= dfs(a, b);
            }
        }
        return f;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size(), m = grid2[0].size();
        int res = 0;
        g1 = grid1;
        g2 = grid2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g2[i][j] == 1) res += dfs(i, j);
            }
        }
        return res;
    }
};
