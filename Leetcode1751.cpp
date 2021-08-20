class Solution {
public:
    int maxValue(vector<vector<int>>& e, int k) {
        int n = e.size();
        sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
        // f[i][j]考虑前i个事件，选择k个事件能得到的最大值
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(k, i); j++) {
                //不选当前事件
                f[i][j] = f[i - 1][j];
                int l = 0, r = i - 1;
                while (l < r) {
                    int mid = l + r + 1>> 1;
                    if (e[mid - 1][1] < e[i - 1][0]) l = mid;
                    else r = mid - 1;
                }
                f[i][j] = max(f[i][j], f[l][j - 1] + e[i - 1][2]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= k; i++) ans = max(ans, f[n][i]);
        return ans;
    }
};
