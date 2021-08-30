// https://leetcode-cn.com/problems/number-of-unique-good-subsequences/solution/bu-tong-de-hao-zi-xu-lie-shu-mu-by-leetc-ej2n/
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        int n = s.size();
        vector<vector<LL>> f(n + 1, vector<LL>(2, 0));
        int zero = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') {
                zero = 1;
                f[i][1] = f[i - 1][1];
                f[i][0] = f[i - 1][0] + f[i - 1][1];
            } else {
                f[i][0] = f[i - 1][0];
                f[i][1] = f[i - 1][1] + f[i - 1][0] + 1;
            }
            f[i][0] %= mod;
            f[i][1] %= mod;
            // debug(i, f[i][0], f[i][1]);
        }
        return (f[n][0] + f[n][1] + zero) % mod;
    }
};
