
typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

// int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

class Solution {
public:
    int concatenatedBinary(int n) {
        LL res = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            if (!(i & (i - 1))) c++;
            res = (res << c) + i;
            res %= mod;
        }
        return res;
    }
};
