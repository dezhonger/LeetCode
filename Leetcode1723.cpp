const int N = 1 << 12;
int f[15][N];
int sum[N];
class Solution {
public:
    //f[i][s]前i个人完成任务状态为s的答案
    //枚举第i个人做的任务集合为sub，f[i][s] = min(f[i][s], max(f[i-1][s^sub], sum{sub});
    int minimumTimeRequired(vector<int>& jobs, int k) {
        memset(f, 0x3f, sizeof f);
        memset(sum, 0, sizeof sum);
        f[0][0] = 0;
        int n = jobs.size();
        for (int i = 0; i < (1 << n); i++) {
            //计算某个人做状态为i的任务需要的总时长
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) sum[i] += jobs[j];
            }
        }

        for (int i = 1; i <= k; i++) {
            for (int s = 0; s < (1 << n); s++) {
                for (int sub = s; sub; sub = (sub - 1) & s) {
                    f[i][s] = min(f[i][s], max(f[i - 1][s ^ sub], sum[sub]));
                }
            }
        }
        return f[k][(1 << n) - 1];
    }
};
