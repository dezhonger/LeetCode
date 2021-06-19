typedef long long LL;
int mod = (int)1e9 + 7;


class Solution {
public:
    int maxProductPath(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<LL>> f1 = vector<vector<LL>>(n, vector<LL>(m, INT_MIN));
        vector<vector<LL>> f2 = vector<vector<LL>>(n, vector<LL>(m, INT_MAX));
        
        f2[0][0] = f1[0][0] = g[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    f1[i][j] = max(g[i][j] * f1[i - 1][j], g[i][j] * f2[i - 1][j]);
                    f2[i][j] = min(g[i][j] * f1[i - 1][j], g[i][j] * f2[i - 1][j]);
                }
                if (j > 0) {
                    f1[i][j] = max(f1[i][j], max(g[i][j] * f1[i][j - 1], g[i][j] * f2[i][j - 1]));
                    f2[i][j] = min(f2[i][j], min(g[i][j] * f1[i][j - 1], g[i][j] * f2[i][j - 1]));
                }
            }
        }

        if (f1[n - 1][m - 1] >= 0) return f1[n - 1][m - 1] % mod;
        return -1;
    }
};

