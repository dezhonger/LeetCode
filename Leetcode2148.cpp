class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 1, r = nums.size() - 2;
        while (l < n && nums[l] == nums[0]) l++;
        while (r >= 0 && nums[r] == nums[n - 1]) r--;
        return max(0, r - l + 1);
        
    }
};
