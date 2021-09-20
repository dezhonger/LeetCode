class Solution {
public:

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        //离散化
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size(), ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            int rmax = nums[i] + n - 1;
            int del = nums.end() - upper_bound(nums.begin() + i, nums.end(), rmax);
            ans = min(ans, i + del);
        }
        return ans + n - m;
    }
};
