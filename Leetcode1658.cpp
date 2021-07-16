class Solution {
public:
    int n;
    int minOperations(vector<int>& nums, int x) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        sum -= x;
        
        int ans = -1, l = 0, s = 0;
        for (int r = 0; r < n; r++) {
            s += nums[r];
            while (l <= r && s > sum) {
                s -= nums[l++];
            }
            if (s == sum) ans = max(ans, r - l + 1);
        }
        
        if (ans == -1) return -1;
        return n - ans;
    }
};
