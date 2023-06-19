class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();

        // 维护 f[mask][j] 表示已经将 mask 代表的元素放到序列的开头，且最后一个元素是第 j 的元素的方案数。
        long long f[1 << n][n];
        memset(f, 0, sizeof(f));

        const int MOD = 1e9 + 7;
        // 从小到大枚举mask，保证了顺序
        for (int i = 1; i < (1 << n); i++) for (int j = 0; j < n; j++) if ((i >> j) & 1) {
            int lastMask = i ^ (1 << j);

            // 只有一个数
            if (lastMask == 0) { f[i][j] = 1; continue; }
            // 枚举上一个数写的什么
            for (int jj = 0; jj < n; jj++) if (nums[j] % nums[jj] == 0 || nums[jj] % nums[j] == 0) f[i][j] = (f[i][j] + f[lastMask][jj]) % MOD;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) ans = (ans + f[(1 << n) - 1][i]) % MOD;
        return ans;
    }
};
