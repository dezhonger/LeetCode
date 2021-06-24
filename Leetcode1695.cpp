const int N = 10010;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> s(n + 1, 0), c(N, 0);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        for (int l = 0, r = 0; r < n; r++) {
            c[nums[r]]++;
            if (c[nums[r]] > 1) {
                while (l < r) {
                    c[nums[l++]]--;
                    if (c[nums[r]] <= 1) break;
                }
            }
            ans = max(ans, s[r + 1] - s[l]);
        }
        return ans;
    }
};
