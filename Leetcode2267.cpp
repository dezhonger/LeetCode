const int N = 102;
int f[N][N][N * 2];

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& g) {
        if (g[0][0] == ')')  return false;
        memset(f, 0, sizeof f);
        int n = g.size(), m = g[0].size();
        f[0][0][1] = 1;
        map<char, int> mp = {{'(', 1}, {')', -1}};      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= n + m; k++) {
                    if (f[i][j][k]) {
                        if (i < n - 1) {
                            int v1 = k + mp[g[i + 1][j]];
                            if (v1 >= 0) f[i + 1][j][v1] = 1;
                        }
                        if (j < m - 1) {
                            int v2 = k + mp[g[i][j + 1]];
                            if (v2 >= 0) f[i][j + 1][v2] = 1;
                        }
                    }
                    if (f[n - 1][m - 1][0]) return 1;
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};
