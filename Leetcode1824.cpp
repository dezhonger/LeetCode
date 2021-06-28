

const int INF = 1e8;
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> f(n, vector<int>(3, INF));
        f[0][0] = f[0][2] = 1;
        f[0][1] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                //这个位置是石头
                if (obstacles[i] == j + 1) f[i][j] = INF;
                else {
                    for (int k = 0; k < 3; k++) {
                        if (k == j && obstacles[i - 1] != k + 1) f[i][j] = min(f[i][j], f[i - 1][k]);
                        if (k != j && obstacles[i - 1] != j + 1) f[i][j] = min(f[i][j], f[i - 1][k] + 1);
                    }
                }
            }
        }
        return min(f[n - 1][0], min(f[n - 1][1], f[n - 1][2]));
    }
};
