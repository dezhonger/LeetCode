class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i - 1, k = 0; k < j; j--) {
                while (k < j && nums[k] + nums[j] <= nums[i]) k++;
                res += j - k;
            }
        }
        return res;
    }
};
