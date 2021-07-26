

// 预处理：每一个 mask 的三进制表示
int mask_span[244][5];
// dp[位置][轮廓线上的 mask][剩余的内向人数][剩余的外向人数]
int dp[25][244][7][7];
// 预处理：每一个 mask 去除最高位、乘 3、加上新的最低位的结果
int truncate[244][3];
class Solution {
private:

    // n3 = n^3
    int m, n, n3;
    
public:
    // 如果 x 和 y 相邻，需要加上的分数
    inline int calc(int x, int y) {
        if (x == 0 || y == 0) {
            return 0;
        }
        // 例如两个内向的人，每个人要 -30，一共 -60，下同
        if (x == 1 && y == 1) {
            return -60;
        }
        if (x == 2 && y == 2) {
            return 40;
        }
        return -10;
    }
    
    int getMaxGridHappiness(int m, int n, int nx, int wx) {
        this -> m = m;
        this -> n = n;
        this -> n3 = 1;
        for (int i = 1; i <= n; i++) n3 *= 3;
        this -> n3 = pow(3, n);
        
        // 预处理
        int highest = this->n3 / 3;
        for (int mask = 0; mask < n3; ++mask) {
            for (int mask_tmp = mask, i = 0; i < n; ++i) {
                // 与方法一不同的是，这里需要反过来存储，这样 [0] 对应最高位，[n-1] 对应最低位
                mask_span[mask][n - i - 1] = mask_tmp % 3;
                mask_tmp /= 3;
            }
            truncate[mask][0] = mask % highest * 3;
            truncate[mask][1] = mask % highest * 3 + 1;
            truncate[mask][2] = mask % highest * 3 + 2;
        }
        
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, nx, wx);
    }
    
    
    // dfs(位置，轮廓线上的 mask，剩余的内向人数，剩余的外向人数)
    int dfs(int pos, int borderline, int nx, int wx) {
        // 边界条件：如果已经处理完，或者没有人了
        if (pos == m * n || nx + wx == 0) {
            return 0;
        }
        // 记忆化
        if (dp[pos][borderline][nx][wx] != -1) {
            return dp[pos][borderline][nx][wx];
        }
        
        int x = pos / n, y = pos % n;
        
        // 什么都不做
        int best = dfs(pos + 1, truncate[borderline][0], nx, wx);
        // 放一个内向的人
        if (nx > 0) {
            best = max(best, 120 + calc(1, mask_span[borderline][0]) \
                                 + (y == 0 ? 0 : calc(1, mask_span[borderline][n - 1])) \
                                 + dfs(pos + 1, truncate[borderline][1], nx - 1, wx));
        }
        // 放一个外向的人
        if (wx > 0) {
            best = max(best, 40 + calc(2, mask_span[borderline][0]) \
                                + (y == 0 ? 0 : calc(2, mask_span[borderline][n - 1])) \
                                + dfs(pos + 1, truncate[borderline][2], nx, wx - 1));
        }

        return dp[pos][borderline][nx][wx] = best;
    }
};
