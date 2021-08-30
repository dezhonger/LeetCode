//https://www.acwing.com/solution/content/13976/
typedef long long LL;
double f[10][30][40];
LL c[50][50];
class Solution {
public:
    double getProbability(vector<int>& balls) {
        memset(f, 0, sizeof f);
        int n = balls.size(), m = 0;
        for (int x: balls) m += x;
        int s = m / 2;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) c[i][j] = 1;
                else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        
        int t = 0;
        //考虑前i种颜色的球、第一个盒子放了j个球，第一个盒子减去第二个盒子颜色数为k的概率
        //k可能为负数做偏移量处理
        f[0][0][2 * n] = 1;
        
        for (int i = 0; i < n; i++) {
            //要保证两个盒子都不超过s个
            for (int j = max(0, t - s); j <= min(s, t); j++) {
                for (int k = -n; k <= n; k++) {
                    int cnt = balls[i];
                    //分母：还有m-t个空位置，要放cnt个球.
                    double d = 1.0 / c[m - t][cnt];
                    
                    // 都放在第一个盒子
                    if (j + cnt <= s)
                        //第一个盒子有这么多种放的方式:c[s - j][cnt
                        f[i + 1][j + cnt][k + 1 + 2 * n] += f[i][j][k + 2 * n] * d * c[s - j][cnt];
                        
                    //都放在第二个盒子
                    f[i + 1][j][k - 1 + 2 * n] += f[i][j][k + 2 * n] * d * c[s - (t - j)][cnt];
                    
                    
                    // 枚举第一个盒子放多少个
                    for (int l = 1; l < cnt; l++) {
                        f[i + 1][j + l][k + 2 * n] += f[i][j][k + 2 * n] * d * c[s - j][l] * c[s - (t - j)][cnt - l];
                    }
                }
            }
            t += balls[i];
        }
        return f[n][s][2 * n];
    }
};
