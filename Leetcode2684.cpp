class Solution {
public:
    int maxMoves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), f[n][m];
        memset(f, 0, sizeof(f));
        for (int j = m - 2; j >= 0; j--)
            for (int i = 0; i < n; i++)
                // 枚举右边一列的3个位置
                for (int k = max(i - 1, 0); k <= min(i + 1, n - 1); k++)
                    if (grid[k][j + 1] > grid[i][j])
                        f[i][j] = max(f[i][j], f[k][j + 1] + 1);
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f[i][0]);
        return ans;
    }
};
