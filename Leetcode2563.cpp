class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); ++j) {
            // lower <= nums[i] + nums[j] <= upper
            // lower - nums[j] <= nums[i] <= upper - nums[j]
            auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
            auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
            ans += r - l;
        }
        return ans;
    }
};
