
typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

const int N = 1010;
LL f[N][N];
LL g[N][26];
LL h1[N], h2[N];
class Solution {
public:
    void add(LL& a, LL b) {
        a += b;
        if (a > mod) a -= mod;
    }
    int numWays(vector<string>& words, string target) {
        int n = target.size(), m = words.size(), l = words[0].size();
        // f[i][j]匹配到第i个字符，用了是words中的第j个位置 的方案数
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        memset(h1, 0, sizeof h1);
        memset(h2, 0, sizeof h2);
        f[0][0] = 1;
        for (int i = 0; i <= l; i++) h1[i] = 1;
        target = ' ' + target;
        for (auto& w: words) w = ' ' + w;
        for (int k = 1; k <= l; k++) {
            for (int j = 0; j < m; j++) {
                g[k][words[j][k] - 'a']++;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= l; j++) {
                //第j个位置和target[i]匹配的有c个字符
                int c = g[j][target[i] - 'a'];
                
                // LL t = 0;
                // for (int k = 0; k < j; k++) add(t, f[i - 1][k]);
                // f[i][j] = c * t % mod;
                
                // debug(i, j, t, h1[j - 1]);
                f[i][j] = c * h1[j - 1] % mod;
                add(h2[j], f[i][j]);
            }
            for (int j = 1; j <= l; j++) add(h2[j], h2[j - 1]);
            for (int j = 0; j <= l; j++) h1[j] = h2[j], h2[j] = 0;
        }
        LL ans = 0;
        for (int j = n; j <= l; j++) add(ans, f[n][j]);
        return ans;
    }
};
