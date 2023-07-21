class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > threshold || nums[i] & 1) continue;
            int j = i + 1;
            while (j < n && nums[j] % 2 != nums[j - 1] % 2 && nums[j] <= threshold) j++;
            ans = max(ans, j - i);
            i = j - 1;
        }
        return ans;
    }
};
