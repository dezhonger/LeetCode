int f[8][8][8][8][80];

class Solution {
public:
    int n, m, cj, mj;
    vector<string> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int dp(int cx, int cy, int mx, int my, int k) {
        if (k >= 80) return 0;
        auto& v = f[cx][cy][mx][my][k];
        if (v != -1) return v;

        if (k & 1) {  // 猫
            for (int i = 0; i < 4; i ++ ) {
                for (int j = 0; j <= cj; j ++ ) {
                    int x = cx + dx[i] * j, y = cy + dy[i] * j;
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') break;
                    if (x == mx && y == my) return v = 0;
                    if (g[x][y] == 'F') return v = 0;
                    if (!dp(x, y, mx, my, k + 1)) return v = 0;
                }
            }
            return v = 1;
        } else {  // 老鼠
            for (int i = 0; i < 4; i ++ ) {
                for (int j = 0; j <= mj; j ++ ) {
                    int x = mx + dx[i] * j, y = my + dy[i] * j;
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') break;
                    if (x == cx && y == cy) continue;
                    if (g[x][y] == 'F') return v = 1;
                    if (dp(cx, cy, x, y, k + 1)) return v = 1;
                }
            }
            return v = 0;
        }
    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        g = grid;
        n = g.size(), m = g[0].size(), cj = catJump, mj = mouseJump;
        int cx, cy, mx, my;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 'C') cx = i, cy = j;
                else if (g[i][j] == 'M') mx = i, my = j;
        memset(f, -1, sizeof f);
        return dp(cx, cy, mx, my, 0);
    }
};

