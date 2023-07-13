class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& ww) {
        int n = ww.size(), N = 26;
        //f[i][j][k] 表示连接了前i个字符串，并且结果已j开头，以k结尾的最小长度
        int f[n][N][N];
        memset(f, 0x3f, sizeof f);
        f[0][ww[0][0] - 'a'][ww[0].back() - 'a'] = ww[0].size();

        for (int i = 1; i < n; i++)
        {
            auto& w = ww[i];
            int len = w.size(), x = w[0] - 'a', y = w.back() - 'a';
            for (int j = 0; j < N; j++) for (int k = 0; k < N; k++)
            {
                // 把w连接开头
                f[i][x][k] = min(f[i][x][k], f[i - 1][j][k] + len - (y == j));
                // 把w连接末尾
                f[i][j][y] = min(f[i][j][y], f[i - 1][j][k] + len - (k == x));
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) ans = min(ans, f[n - 1][j][k]);
        return ans;
    }
};
