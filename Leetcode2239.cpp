class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] >= 0) return nums[0];
        if (nums[n - 1] <= 0) return nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] <= 0 && nums[i] >= 0)
            {
                if (abs(nums[i - 1]) < nums[i]) return nums[i - 1];
                else return nums[i];
            }
        }
        return -1000;
    }
};
