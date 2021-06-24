typedef long long LL;
int mod = (int)1e9 + 7;


class Solution {
public:
    LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> cnt;
        LL ans = 0;
        for (int x : deliciousness) cnt[x]++;
        for (int j = 0; j < deliciousness.size(); j++) {
            for (int i = 1; i <= (1 << 21); i <<= 1) {
                int d = i - deliciousness[j];
                if (d != deliciousness[j]) ans += cnt[d];
                else ans += cnt[d] - 1;
                ans %= mod;
            }
        }
        return ans * powmod(2, mod - 2) % mod;
    }
};
