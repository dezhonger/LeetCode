//https://leetcode.cn/problems/minimum-cost-to-make-array-equal/solution/by-tsreaper-8hxm/
class Solution {
    typedef pair<int, int> pii;

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pii> vec;
        for (int i = 0; i < n; i++) vec.push_back(pii(nums[i], cost[i]));
        sort(vec.begin(), vec.end());

        // f[i] = sum(a[i] * b[i]), g[i] = sum(b[i])
        vector<long long> f(n + 1), g(n + 1);
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + 1LL * vec[i - 1].first * vec[i - 1].second;
            g[i] = g[i - 1] + vec[i - 1].second;
        }

        long long ans = 1e18;
        // 枚举 x（也就是枚举 k）
        for (int i = 1; i <= n; i++) {
            // 套公式
            long long L = vec[i - 1].first * g[i - 1] - f[i - 1];
            long long R = (f[n] - f[i]) - vec[i - 1].first * (g[n] - g[i]);
            ans = min(ans, L + R);
        }
        return ans;
    }
};
