typedef long long LL;


class Solution {
public:
    unordered_map<LL, int> mp, mq;
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<LL> f(n + 1);
        for (int i = 0; i < n; i++) f[i + 1] = f[i] + nums[i];
        for (LL i = 0, s = 0; i < n - 1; i++) {
            s += nums[i];
            mp[s]++;
        }
        LL s = f[n];
        if (s % 2 == 0) ans = max(ans, mp[s / 2]);
        if ((s + k - nums[n - 1]) % 2 == 0) ans = max(ans, mp[(s + k - nums[n - 1]) / 2]);
        for (int i = n - 2; i >= 0; i--) {
            int add = k - nums[i];
            s += add;
            mp[f[i + 1]]--;
            mq[f[i + 1]]++;
            if (s % 2 == 0) ans = max(ans, mp[s / 2] + mq[s / 2 - add]);
            s -= add;
        }
        return ans;
    }
};
