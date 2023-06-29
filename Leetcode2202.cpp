class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int res = -1;   // 最大的栈顶元素
        if (n == 1) {
            if (k % 2 == 0) res = nums[0];
            else return -1;
        } else {
            for (int i = 0; i < min(n, k + 1); ++i) {
                if (i != k - 1) res = max(res, nums[i]);
            }
        }
        return res;
    }
};
