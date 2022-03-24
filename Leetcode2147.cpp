typedef long long LL;
LL mod = 1000000007;

class Solution {
public:
    int numberOfWays(string corridor) {
        LL t = 1, c = 0, pos = -1;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                c++;
                if (c > 1 && c % 2 == 1) t *= (i - pos), t %= mod;
                pos = i;
            }
        }
        return (c > 1 && c % 2 == 0) ? t : 0;
    }
};
