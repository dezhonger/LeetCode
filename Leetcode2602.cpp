class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> res(queries.size()), s(n + 1);;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        for (int t = 0; t < queries.size(); t++)
        {
            int q = queries[t];
            int x = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            res[t] =  1LL * q * x - s[x] + s.back() - s[x] - 1LL * q * (n - x);
        }
        return res;
    }
};
