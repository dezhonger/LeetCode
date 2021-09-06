const int N = 30;
// f[k][x][y] 当前一共k个人，其中firstPlayer左边有x个人，secondPlayer右边有y个人，这种状态是否可达
bool f[N][N][N];


class Solution {
public:
    vector<int> earliestAndLatest(int n, int a, int b) {
        memset(f, 0, sizeof f);
        f[n][a - 1][n - b] = true;
        for (int k = n; k > 1; k = (k + 1) / 2) {
            for (int x = 0; x < k; x++) for (int y = 0; y < k; y++) {
                if (f[k][x][y]) {
                    // m1上取整 m2下取整
                    int m2 = k / 2, m1 = k - m2;
                    
                    // 以下代码假设奇数的时候上半区比下半区多一个人
                    if (y >= m2) {
                        // ab都在上半部分
                        // a和b之间的人数
                        int z = k - x - y - 2;
                        for (int i = 0; i <= x; i++) for (int j = 0; j <= z; j++) {
                            f[m1][i][j + x - i + y - m2] = true;
                        }
                    } else if (x >= m1) {
                        // ab都在下半部分
                        int z = k - x - y - 2;
                        for (int i = 0; i <= y; i++) for (int j = 0; j <= z; j++) {
                            f[m1][y - i + j + x - m2][i] = true;
                        }
                    } else if (x < y) {
                        // 在两侧
                        int z = y - x - 1;
                        for (int i = 0; i <= x; i++) for (int j = 0; j <= z; j++) {
                            f[m1][i][j + x - i] = true;
                        }
                    } else if (x > y) {
                        int z = x - y - 1;
                        for (int i = 0; i <= y; i++) for (int j = 0; j <= z; j++) {
                            f[m1][y - i + j][i] = true;
                        }
                    }
                }
            }
        }
        int r1 = INT_MAX, r2 = INT_MIN;
        for (int k = n, t = 1; k > 1; k = (k + 1) / 2, t++) {
            for (int i = 0; i < k / 2; i++) {
                if (f[k][i][i]) {
                    r1 = min(r1, t);
                    r2 = max(r2, t);
                }
            }
        }
        return {r1, r2};
    }
};
