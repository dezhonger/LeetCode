class Solution {
public:
    int countPyramids(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        vector<vector<int>> f(n, vector<int>(m));
        vector<vector<int>> h(n, vector<int>(m));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) f[i][j] = -1;
                else if (i == n - 1 || j == 0 || j == m - 1) f[i][j] = 0;
                else f[i][j] = min({f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]}) + 1, ans += f[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) h[i][j] = -1;
                else if (i == 0 || j == 0 || j == m - 1) h[i][j] = 0;
                else h[i][j] = min({h[i - 1][j - 1], h[i - 1][j], h[i - 1][j + 1]}) + 1, ans += h[i][j];
            }
        }
        
        return ans;
    }
};
