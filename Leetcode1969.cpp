typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }
LL powmod(LL a,LL b, int mod) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


class Solution {
public:
    int minNonZeroProduct(int p) {
        // int n = 2 ^ p - 1
        LL res = powmod(2, p) - 1;
        if (res < 0) res += mod;
        LL a = powmod(2, p) - 2;
        if (a < 0) a += mod;
        //欧拉降幂 a^b %p(gcd(a, p) == 1)  等于a^(b % phi(p)) % p
        LL c = powmod(2, p - 1, mod - 1);
        if (c >= 0) c --;
        else c += mod - 1;
        // debug(res, a, c);
        a = powmod(a, c);
        res *= a;
        return res % mod;
    }
};
