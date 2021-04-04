const int N = 110;
int f[N][N];

class Solution {
public:

    int dis(int a, int b, int m) {
        if (a > b) swap(a, b);
        return min(b - a, a - b + m);
    }

    int findRotateSteps(string ring, string key) {
        memset(f[0], 0x3f, sizeof f[0]);
        f[0][0] = 0;
        int n = key.size(), m = ring.size();
        for (int i = 1; i <= n; i++) {
            memset(f[i], 0x3f, sizeof f[i]);
            for (int j = 0; j < m; j++) {
                if (ring[j] == key[i - 1]) {
                    for (int k = 0; k < m; k++)
                        f[i][j] = min(f[i][j], f[i - 1][k] + dis(k, j, m) + 1);
                }
            }
        }
        int res = 0x3f3f3f3f;
        for (int k = 0; k < m; k++) res = min(res, f[n][k]);
        return res;
    }
};
