class Solution {
public:
    long long maxScore(vector<int> &nums, int x) {
        int size = nums.size();
        long long dp[size][2];//i之前停留在偶数或者奇数的最大值
        dp[0][nums[0] & 1] = nums[0];
        dp[0][1 - (nums[0] & 1)] = -x; // <= nums[0] - x即可
        for (int i = 1; i < nums.size(); i++) {
            dp[i][nums[i] & 1] = max(dp[i - 1][nums[i] & 1] + nums[i], dp[i - 1][1 - (nums[i] & 1)] + nums[i] - x);
            dp[i][1 - (nums[i] & 1)] = dp[i - 1][1 - (nums[i] & 1)];
        }
        return max(dp[size -1][0] , dp[size -1][1]);
    }


};
