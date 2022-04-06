typedef long long LL;
int f[1010][1010];
int sum[1010];
class Solution {
public:
    int minimumWhiteTiles(string floor, int cnt, int len) {
        int n = floor.size();
        string s = " " + floor;
        memset(f, 0, sizeof f);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] == '1');
        for (int i = 1; i < len; i++) {
            for (int j = 1; j <= cnt; j++) f[i][j] = sum[i];
        }
        for (int i = len; i <= n; i++) {
            for (int j = 0; j <= cnt; j++) {
                f[i][j] = f[i - 1][j];
                if (j) f[i][j] = max(f[i - len][j - 1] + sum[i] - sum[i - len], f[i][j]);
            }
        }
        return sum[n] - f[n][cnt];
    }
};
