class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), ans = -1, minV = nums[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, (nums[i] - minV) > 0 ? nums[i] - minV : -1);
            minV = min(minV, nums[i]);
        }
        return ans;
    }
};
