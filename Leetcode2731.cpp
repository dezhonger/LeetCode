class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        const long long mod = (1e9)+7;
        vector<long long> pos(n), sum(n + 1);
        for (int i = 0; i < n; i++) pos[i] = (long long)nums[i] + d  * (s[i] == 'L' ? - 1: 1);
        
        sort(pos.begin(), pos.end());
        for (int i = n - 1; i >= 0; i--) sum[i] = sum[i + 1] + pos[i];
        long long res = 0;
        for (int i = 0; i < n - 1; i++) res += sum[i + 1] - pos[i] * (n - i - 1), res %= mod;
        return res;
    }
};
