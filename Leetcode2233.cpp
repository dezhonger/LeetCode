class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1000000007;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        nums.push_back(INT_MAX);
        // 遍历数组，优化模拟更新的过程
        for (int i = 0; i < n; ++i) {
            // 判断是否可以将数组下标 [0, i] 的元素更新为 nums[i+1]
            long long tmp = (long long) (i + 1) * (nums[i+1] - nums[i]);
            if (k >= tmp) {
                // 可以，则更新剩余的操作次数
                k -= tmp;
                continue;
            }
            // 不可以，则计算最终数组的元素
            int d = k / (i + 1);
            int m = k % (i + 1);
            for (int j = 0; j <= i; ++j) {
                nums[j] = nums[i] + d;
                if (j < m) {
                    ++nums[j];
                }
            }
            break;
        }
        nums.pop_back();
        int res = 1;
        for (int num: nums) {
            res = (long long) num * res % mod;
        }
        return res;
    }
};
