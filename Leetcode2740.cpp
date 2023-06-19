class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) res = min(res, nums[i] - nums[i - 1]);
        return res;
    }
};
