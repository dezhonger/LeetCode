class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        const double eps = 1e-8;
        int n = dist.size();
        //f[i][j] 前i个路径休息j次的最短时间
        vector<vector<double>> f(n + 1, vector<double>(n + 1));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            double time = 1.0 * dist[i - 1] / speed;
            for (int j = 0; j <= i; j++) {
                f[i][j] = 1e8;
                //第i次不休息
                if (j <= i - 1) f[i][j] = min(f[i][j], ceil(f[i - 1][j] + time - eps));
                //第i次休息
                if (j > 0) f[i][j] = min(f[i][j], f[i - 1][j - 1] + time);
            }
        }
        for (int j = 0; j <= n; j++) {
            if (f[n][j] <= hoursBefore) return j;
        }
        return -1;
    }
};
