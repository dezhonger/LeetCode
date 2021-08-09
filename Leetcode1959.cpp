const int maxn = 205;
class Solution {
public:
    
    int Logn[maxn + 1];
    void pre() {
        Logn[1] = 0;
        Logn[2] = 1;
        for (int i = 3; i < maxn; i++) {
            Logn[i] = Logn[i / 2] + 1;
        }
    }
    

    int minSpaceWastedKResizing(vector<int>& a, int k) {
        int c = k + 1;
        // g[i][j] 前i位分为j段的最小花费，ans = g[n][c]
        int n = a.size();
        
        // ST表
        vector<vector<int>> f(n + 1, vector<int>(11));
        for (int i = 1; i <= n; i++) f[i][0] = a[i - 1];
        pre();
        for (int j = 1; j <= 10; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        // 前缀和
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        
        // dp
        vector<vector<int>> g(n + 1, vector<int>(c + 1, 1e8));
        g[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, c); j++) {
                if (j == 1) {
                    int x = 1, y = i, z = Logn[y - x + 1];
                    int mv = max(f[x][z], f[y - (1 << z) + 1][z]);
                    int diff = mv * (y - x + 1) - (s[y] - s[x - 1]);
                    g[i][j] = diff;
                } else {
                    for (int k = j - 1; k < i; k++) {
                        int x = k + 1, y = i, z = Logn[y - x + 1];
                        int mv = max(f[x][z], f[y - (1 << z) + 1][z]);
                        int diff = mv * (y - x + 1) - (s[y] - s[x - 1]);
                        g[i][j] = min(g[i][j], g[k][j - 1] + diff);
                    }
                }
            }
        }
        return g[n][c];
    }
};
