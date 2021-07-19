
template<typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }

const int N = 2005;
// 第i个数换为b数组的第j个数的答案
int f[N][N];
// 第i个数不换的答案
int g[N];


class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int n = a.size(), m = b.size();
        memset(f, 0x3f, sizeof f);
        memset(g, 0x3f, sizeof g);
        for (int j = 0; j < m; j++) f[0][j] = 1;
        g[0] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) upmin(g[i], g[i - 1]);
            for (int j = 0; j < m; j++) if (a[i] > b[j]) upmin(g[i], f[i - 1][j]);
            for (int j = 0; j < m; j++) if (b[j] > a[i - 1]) upmin(f[i][j], g[i - 1] + 1);
            int minV = f[i - 1][0];
            for (int j = 1; j < m; j++) {
                upmin(f[i][j], minV + 1);
                upmin(minV, f[i - 1][j]);
            }
        }
        int ans = g[n - 1];
        for (int j = 0; j < m; j++) upmin(ans, f[n - 1][j]);
        if (ans >= 0x3f3f3f3f) return -1;
        return ans;
    }
};
