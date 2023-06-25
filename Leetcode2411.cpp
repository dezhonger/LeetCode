class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), dp(32, INT_MAX);
        for (int i = n - 1; i >= 0; i--)
        {
            int y = 0;
            for (int k = 0; k < 32; k++) if ((nums[i] >> k) & 1) dp[k] = min(dp[k], i);
            for (int k = 0; k < 32; k++) if (dp[k] != INT_MAX) y = max(y, dp[k]);
            res[i] = max(1, y - i + 1);
        }
        return res;
    }
};
