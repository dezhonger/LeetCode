class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0, j = n - 1, s1 = 0, s2 = 0; i < n; i++, j--) {
            res[i] += i * nums[i] - s1;
            res[j] += s2 - (n - j - 1) * nums[j];
            s1 += nums[i];
            s2 += nums[j];
        }
        return res;
    }
};
