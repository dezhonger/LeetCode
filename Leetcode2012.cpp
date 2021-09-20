class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> f(n), g(n);
        f[0] = nums[0], g[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) f[i] = max(f[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--) g[i] = min(g[i + 1], nums[i + 1]);
        for (int i = 1; i < n - 1; i++) {
            if (f[i - 1] < nums[i] && nums[i] < g[i + 1]) ans += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) ans += 1;
        }
        return ans;
    }
};
