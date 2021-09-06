typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }
const int N = 1024;
int cnt[N], f[2][N];
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        memset(cnt, 0, sizeof cnt);
        memset(f, 0, sizeof f);
        for (int x: nums) {
            int y = 0;
            bool f = true;
            for (int i = 0; i < p.size(); i++) {
                if (x % p[i] == 0) {
                    y |= (1 << i);
                    x /= p[i];
                    if (x % p[i] == 0) {
                        f = false;
                        break;
                    }
                }
            }
            if (f) cnt[y]++;
        }
        // const int N = 1024;
        // vector<vector<LL>> f(2, vector<LL>(N));
        int t = 1;
        f[0][0] = 1;
        //前i个数集合为状态为j的方案数
        for (int i = 1; i < N; i++, t = 1 - t) {
            for (int j = 0; j < N; j++) {
                f[t][j] = f[1 - t][j];
                if (cnt[i] && (j & i) == i) f[t][j] += (1LL * cnt[i] * f[1 - t][j ^ i]) % mod;
                f[t][j] %= mod;
            }
        }
        int ans = 0;
        for (int i = 1; i < N; i++) ans = (ans + f[1][i]) % mod;
        ans = (1LL * ans * powmod(2, cnt[0])) % mod;
        return ans;
    }
};
