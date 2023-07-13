class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(n, -1);
        f[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int dis = abs(nums[j] - nums[i]);
                if (dis <= target && f[j] != -1) f[i] = max(f[i], f[j] + 1);
            }
        }
        return f[n - 1];
    }
};
