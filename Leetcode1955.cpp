typedef long long LL;

int mod = (int)1e9 + 7;


class Solution {
public:
    // dp[i][0/1/2] 前i位中，以0/1/2结尾的序列的个数
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<LL>> dp(n + 1, vector<LL>(3));
        for (int i = 1; i <= n; i++) {
            int t = nums[i - 1];
            for (int j = 0; j < 3; j++) dp[i][j] = dp[i - 1][j];
            
            if (t == 0) dp[i][t] += 1 + dp[i - 1][0];
            else if (t == 1) dp[i][t] += dp[i - 1][0] + dp[i - 1][1];
            else dp[i][t] += dp[i][1] + dp[i - 1][t];
            for (int j = 0; j < 3; j++) dp[i][j] %= mod;
        }
        return dp[n][2];
    }
};
