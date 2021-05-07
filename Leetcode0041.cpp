class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;
        for (int& x: nums) if (x != INT_MIN) x--;
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]] && nums[i] != i) swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < n; i++) if (i != nums[i]) return i + 1;
        return n + 1;
    }
};

