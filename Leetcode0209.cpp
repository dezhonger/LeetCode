class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int res = n + 100;
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int j = 0;
        for (int i = 1; i <= n; i++) {
            while (s[i] - s[j] >= t) j++;
            if (j > 0 && s[i] - s[j - 1] >= t) res = min(res, i - j + 1);
        }
        if (res == n + 100) res = 0;
        return res;
    }
};
