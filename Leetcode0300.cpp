class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        //f[i]: 长度为i的LIS结尾的最小元素
        vector<int> f(n + 1, -1e8);
        //f[0] = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int l = 0, r = res;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (f[mid] < nums[i]) l = mid;
                else r = mid - 1;
            }
            
            f[l + 1] = nums[i];
            res = max(res, l + 1);
            
        }
        return res;

    }
};
