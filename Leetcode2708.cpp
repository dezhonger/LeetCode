class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long res = LLONG_MIN;
        for (int i = 1; i < (1 << n); i++)
        {
            long long s = 1;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1) s *= nums[j];
            }
            res = max(res, s);
        }
        return res;
    }
};
