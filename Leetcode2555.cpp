class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        int ans = 0, n = p.size();
        // f[i] 以i为右端点的位置，能覆盖的奖品
        // g[i] 以[0, i]为右端点的位置，能覆盖的奖品的最大值
        vector<int> f(n), g(n);
        for (int l = 0, r = 0, rr = -1; r < n; r++)
        {
            while (l < r && p[r] - p[l] > k) l++;
            f[r] = r - l + 1;
            g[r] = max(f[r], r ? g[r - 1]: 0);

            while (p[rr + 1] + k < p[r]) rr++;
            ans = max(ans, f[r] + (rr >= 0 ? g[rr] : 0));
        }

        return ans;
    }
};
