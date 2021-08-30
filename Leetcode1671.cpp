class Solution {
public:
    vector<int> cal(vector<int>& a) {
        int n = a.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
            }
        }
        return f;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        // 求以nums[i]为开头和结尾的最长上升和下降子序列求个最小值
        vector<int> v(nums.begin(), nums.end());
        reverse(v.begin(), v.end());
        auto f = cal(nums);
        auto g = cal(v);
        int ans = n;
        for (int i = 1; i < n - 1; i++) if (f[i] >= 2 && g[n - 1 - i] >= 2) 
            ans = min((i + 1 - f[i]) + (n - i - g[n - 1 - i]), ans);
        return ans;
    }
};
