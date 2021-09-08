int dx[4] = {-1, 0}, dy[4] = {0, -1};
const int N = 500 * 500 + 10;
int f[N];

int find(int x) {
    return f[x] == x ? x : find(f[x]);
}

bool merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return false;
    f[fx] = find(fy);
    return true;
}

class Solution {
public:
    int n, m;
    inline int cal(int x, int y) {
        return x * m + y;
    }
    bool containsCycle(vector<vector<char>>& g) {
        n = g.size(), m = g[0].size();
        for (int i = 0; i < m * n; i++) f[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 2; k++) {
                    int ii = i + dx[k], jj = j + dy[k];
                    if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
                        if (g[ii][jj] == g[i][j]) {
                            if(!merge(cal(ii, jj), cal(i, j))) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
