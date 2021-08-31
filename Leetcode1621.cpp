typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

// int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

const int N = 1010;
LL f[N][N][2];

class Solution {
public:
    int numberOfSets(int n, int k) {
        memset(f, 0, sizeof f);
        n--;
        // f[i][j]前i个点，覆盖了j个线段，且最后一条线段的右端点不是i
        // f[i][j]前i个点，覆盖了j个线段，且最后一条线段的右端点是i
        
        //初始化条件
        f[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                f[i][j][0] = f[i - 1][j][0] + f[i - 1][j][1];
                f[i][j][0] %= mod;
                
                //最后加一条长度为1的线段
                if (j) f[i][j][1] = f[i - 1][j - 1][0] + f[i - 1][j - 1][1];
                //把前面的一条线段延长
                f[i][j][1] += f[i - 1][j][1];
                f[i][j][1] %= mod;
            }
            
        }
        return (f[n][k][0] + f[n][k][1]) % mod;
    }
};
