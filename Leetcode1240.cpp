// http://int-e.eu/~bf3/squares/view.html#24,43 演示答案

const int N = 20;
int f[N][N], g[N][N];
class Solution {
public:
    int n, m, ans;
    inline bool can(int s, int x, int y) {
        if (s + x > n || s + y > m) return false;
        for (int i = x; i < s + x; i++) {
            for (int j = y; j < s + y; j++) {
                if (f[i][j]) return false;
            }
        }
        return true;
    }
    
    inline void fill(int s, int x, int y, int v) {
        for (int i = x; i < s + x; i++) {
            for (int j = y; j < s + y; j++) {
                f[i][j] = v;
            }
        }
    }
    int dfs(int x, int y, int has) {
        if (has > m) return INT_MAX;
        if (g[x][y] != 0x3f3f3f3f && g[x][y] < has) return INT_MAX;
        if (x == n) {
            ans = min(ans, has);
            return ans;
        }
        int& ans = g[x][y];
        if (y == m) {
            ans = min(ans, dfs(x + 1, 0, has));
            return ans;
        }
        if (f[x][y]) {
            ans = min(ans, dfs(x, y + 1, has));
            return ans;
        }
        
        for (int s = n; s > 0; s--) {
            if (!can(s, x, y)) continue;
            fill(s, x, y, 1);
            ans = min(ans, dfs(x, y + s, has + 1));
            fill(s, x, y, 0);
        }
        return ans;
    }
    int tilingRectangle(int _n, int _m) {
        n = _n, m = _m;
        if (n > m) swap(n, m);
        ans = m;
        memset(f, 0, sizeof f);
        memset(g, 0x3f, sizeof g);
        dfs(0, 0, 0);
        return ans;
    }
};
