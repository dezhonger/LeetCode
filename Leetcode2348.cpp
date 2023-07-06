class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, t = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0) t++, res += t;
            else t = 0;
        }
        return res;
    }
};
