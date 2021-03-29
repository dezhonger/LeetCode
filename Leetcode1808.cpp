typedef long long LL;
const int mod = 1000000007;
class Solution {
public:
    LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

    int maxNiceDivisors(int x) {
        long long res = 1;
        
        if (x <= 3) return x;
        if (x % 3 == 0) {
            return powmod(3, x / 3);
        } else if (x % 3 == 1) {
            res = powmod(3, (x - 4) / 3);
            res *= 4;
            res %= mod;
            return res;

        } else {
            
            res = powmod(3, x / 3);
            res *= 2;
            res %= mod;
            return res;
        }
    }
};
