class Solution {
public:
    vector<int> s;
    int f[510][510];
    int dfs(int l, int r) {
        if (l >= r) return 0;
        if (f[l][r] != -1) return f[l][r];
        int res = 0;
        for (int i = l; i < r; i++) {
            //[l, i], [i + 1, r]
            int lsum = s[i] - s[l - 1], rsum = s[r] - s[i];
            if (lsum < rsum) {
                res = max(res, lsum + dfs(l, i));
            } else if (lsum > rsum) {
                res = max(res, rsum + dfs(i + 1, r));
            } else {
                res = max(res, max(lsum + dfs(l, i), rsum + dfs(i + 1, r)));
            }
        }
        f[l][r] = res;
        return res;
    }
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        s = vector<int>(n + 1);
        memset(f, -1, sizeof f);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        return dfs(1, n);
    }
};
