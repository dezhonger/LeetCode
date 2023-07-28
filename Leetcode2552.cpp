class Solution {
public:
    typedef long long LL;
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        LL ans = 0;
        vector<vector<int>> g(n + 10, vector<int>(n + 10));
        vector<vector<int>> h(n + 10, vector<int>(n + 10));

        for (int i = n - 2; i >= 0; i--)
        {
            // g[i][j]在下标i右边且比nums[j]大的数的个数
            for (int j = 0; j <= n; j++) g[i][j] = g[i + 1][j];
            for (int v = nums[i + 1] - 1; v >= 0; v--) g[i][v]++;
        }

        for (int i = 1; i < n; i++)
        {
            // h[i][k]在下标i左边且比nums[j]小的数的个数
            for (int j = 0; j <= n; j++) h[i][j] = h[i - 1][j];
            for (int v = nums[i - 1] + 1; v <= n; v++) h[i][v]++; 
        }

        // 枚举中间的两个数
        for (int j = 1; j < n - 2; j++) for (int k = j + 1; k < n - 1; k++)
        {
            if (nums[j] > nums[k]) ans += (h[j][nums[k]] * g[k][nums[j]]);
        }
        return ans;
    }
};
