const int MOD = 1e9 + 7, MX = 1e4 + 1;
int f[MX] = {1, 2};
int init = []() {
    for (int i = 2; i < MX; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    return 0;
}();

class Solution {
public:
    int countHousePlacements(int n) {
        return (long) f[n] * f[n] % MOD;
    }
};
