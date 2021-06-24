
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), ans = abs(nums[0]);
        vector<int> f1(n), f2(n);
        f1[0] = f2[0] = nums[0];
        for (int i = 1; i < n; i++) {
            f1[i] = max(nums[i], f1[i - 1] + nums[i]);
            f2[i] = min(nums[i], f2[i - 1] + nums[i]);
            ans = max(ans, abs(f1[i]));
            ans = max(ans, abs(f2[i]));
        }
        return ans;
    }
};
