class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int w = nums[n - 1], x = nums[n - 2], y = nums[0], z = nums[1];
        return w * x - y * z;
        
    }
};
