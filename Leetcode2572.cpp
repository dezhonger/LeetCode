//https://leetcode.cn/problems/count-the-number-of-square-free-subsets/solution/liang-chong-xie-fa-01bei-bao-zi-ji-zhuan-3ooi/
class Solution {
    static constexpr int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    static constexpr int MOD = 1e9 + 7, MX = 30, N_PRIMES = 10, M = 1 << N_PRIMES;
public:
    int squareFreeSubsets(vector<int> &nums) {
        int sf2mask[MX + 1]{}; // sf2mask[i] 为 i 的质因子集合（用二进制表示）
        for (int i = 2; i <= MX; ++i)
            for (int j = 0; j < N_PRIMES; ++j) {
                int p = PRIMES[j];
                if (i % p == 0) {
                    if (i % (p * p) == 0) { // 有平方因子
                        sf2mask[i] = 0;
                        break;
                    }
                    sf2mask[i] |= 1 << j; // 把 j 加到集合中
                }
            }

        int cnt[MX + 1]{}, pow2 = 1;
        for (int x : nums)
            if (x == 1) pow2 = pow2 * 2 % MOD;
            else ++cnt[x];

        long f[M]{pow2}; // f[j] 表示恰好组成质数集合 j 的方案数，其中用 1 组成空质数集合的方案数为 pow2
        for (int x = 2; x <= MX; ++x) {
            int mask = sf2mask[x], c = cnt[x];
            if (mask && c) {
                int other = (M - 1) ^ mask, j = other; // mask 的补集 other
                do { // 枚举 other 的子集 j
                    f[j | mask] = (f[j | mask] + f[j] * cnt[x]) % MOD; // 不选 mask + 选 mask
                    j = (j - 1) & other;
                } while (j != other);
            }
        }
        return accumulate(f, f + M, -1L) % MOD; // -1 表示去掉空集（nums 的空子集）
    }
};
