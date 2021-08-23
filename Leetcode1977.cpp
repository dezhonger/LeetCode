typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

// LL f[3510][3510];
// LL g[3510][3510];
class Solution {
public:
    
    inline bool compare(int x, int y, int z, string& num, vector<vector<int>>& lcp) {
        if (lcp[x][y] >= z) return 1;
        int w = lcp[x][y];
        return num[x + w] < num[y + w];
    }
    
    int numberOfCombinations(string num) {
        int n = num.size();
        num = ' ' + num;
        
        // 预处理 lcp
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
        for (int i = n; i >= 1; --i) {
            lcp[i][n] = (num[i] == num[n]);
            for (int j = i + 1; j < n; ++j) {
                lcp[i][j] = (num[i] == num[j] ? lcp[i + 1][j + 1] + 1 : 0);
            }
        }
        
        
        vector<vector<LL>> f = vector<vector<LL>>(n + 1, vector<LL>(n + 1));
        vector<vector<LL>> g = vector<vector<LL>>(n + 1, vector<LL>(n + 1));
        f[0][0] = 1;
        if (num[1] != '0') for (int i = 1; i <= n; i++) f[i][i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                int lastPos = i - j;
                if (num[lastPos + 1] == '0') continue;
                int l = 1, r = min(j, lastPos);
                if (r == j) {
                    int k = j;
                    if (compare(lastPos - k + 1, lastPos + 1, k, num, lcp)) f[i][j] += f[lastPos][k];
                    if (l <= r - 1) f[i][j] += g[lastPos][r - 1] - g[lastPos][l - 1];
                } else if (r < j && l <= r) f[i][j] += g[lastPos][r] - g[lastPos][l - 1];
                
                if (f[i][j] < 0) f[i][j] += mod;
                f[i][j] %= mod;
                
            }
            for (int j = 1; j <= i; j++) g[i][j] = g[i][j - 1] + f[i][j], g[i][j] %= mod;
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += f[n][i];
            ans %= mod;
        }
        return ans;
    }
};
