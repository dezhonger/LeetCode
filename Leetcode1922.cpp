typedef long long LL;
int mod = (int)1e9 + 7;

class Solution {
public:
    LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    int countGoodNumbers(long long n) {
        LL o = (n + 1) / 2, j = n - o;
        // o %= mod, j %= mod;
        LL ans = powmod(5, o);
        LL jj = powmod(4, j);
        ans *= jj;
        ans %= mod;
        return ans;
    }
};
