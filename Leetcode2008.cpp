class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[1] < b[1];
        });
        vector<long long> f(m), g(m);
        f[0] = g[0] = rides[0][2] + rides[0][1] - rides[0][0];
        for (int i = 1; i < m; i++) {
            int start = rides[i][0], profit = rides[i][2] + rides[i][1] - rides[i][0];
            f[i] = profit;
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (rides[mid][1] <= start) l = mid;
                else r = mid - 1;
            }
            if (l >= 0 && rides[l][1] <= start) f[i] = max(f[i], g[l] + profit);
            g[i] = max(i > 0 ? g[i - 1] : 0, f[i]);
        }
        return g[m - 1];
    }
};
