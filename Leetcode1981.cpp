class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> f(n + 1, vector<bool>(target + 1));
        f[0][0] = true;
        //上一行大于target的最小值
        int large = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int t = INT_MAX;
            for (int k = 0; k < m; k++) {
                for (int j = max(i, mat[i - 1][k]); j <= target; j++) {
                    f[i][j] = f[i][j] | f[i - 1][j - mat[i - 1][k]];
                }
                for (int j = 0; j <= target; j++) {
                    if (f[i - 1][j] && j + mat[i - 1][k] > target) t = min(t, j + mat[i - 1][k]);
                }
                if (large != INT_MAX) t = min(t, large + mat[i - 1][k]);
            }
            large = t;
        }
        int ans = INT_MAX;
        if (large != INT_MAX) ans = large - target;
        for (int i = target; i >= 0; i--) {
            if (f[n][i]) ans = min(ans, target - i);
        }
        return ans;
    }
};
