class Solution {
public:
    long long minCost(vector<int> &nums, int x) {
        int n = nums.size();
        long long sum[n];
        for (int i = 0; i < n; i++) sum[i] = (long long) i * x;
        for (int i = 0; i < n; i++) {
            int mn = nums[i];
            for (int k = i + n, count = 0; count < n; k--, count++)
            {
                mn = min(mn, nums[k % n]);
                sum[count] += mn;
            }
        }
        return *min_element(sum, sum + n);
    }
};
