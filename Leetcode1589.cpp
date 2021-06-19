typedef long long LL;
int mod = (int)1e9 + 7;


class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (auto& x : requests) s[x[0]]++, s[x[1] + 1]--;
        for (int i = 1; i < n; i++) s[i] += s[i - 1];
        sort(s.begin(), s.begin() + n);
        sort(nums.begin(), nums.end());
        LL res = 0;
        for (int i = 0; i < n; i++) {
            res += 1LL * nums[i] * s[i];
            res %= mod;
        }
        return res;   
    }
};
