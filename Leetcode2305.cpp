class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> s(1 << n);
        for (int i = 0; i < (1 << n); i++)
        {
            int t = 0;
            for (int j = 0; j < n; j++) if ((i >> j) & 1) t += cookies[j];
            s[i] = t;
        }

        vector<vector<int>> f(k + 1, vector<int>((1 << n)));
        for (int j = (1 << n) - 1; j > 0; j--) f[1][j] = s[j];
        for (int i = 2; i <= k; i++)
        {
            for (int j = (1 << n) - 1; j > 0; j--)
            {
                f[i][j] = INT_MAX;
                for (int t = j; t; t = (t - 1) & j)
                {
                    f[i][j] = min(f[i][j], max(f[i - 1][j ^ t], s[t]));
                }
            }
        }

        return f[k][(1 << n) - 1];
    }
};
