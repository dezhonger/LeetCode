int f[101][10001];
class Solution {
public:
    int superEggDrop(int k, int n) {
        //i个鸡蛋扔j次能确定的最大楼层
        //f[i][j] = f[i - 1][j - 1] + 1 + f[i - 1][j];
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= k; i++) {
                f[i][j] = f[i - 1][j - 1] + 1 + f[i][j - 1];
            }
            if (f[k][j] >= n) return j;
        }
        return -1;
    }
};
