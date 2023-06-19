class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] + nums[i - 1];
        vector<int> res(n, -1);
        for (int i = k; i + k < n; i++) res[i] = (f[i + k + 1] - f[i - k]) / (k * 2 + 1);
        return res;
    }
};
