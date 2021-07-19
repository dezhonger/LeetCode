typedef long long LL;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int n = p.size(), m = p[0].size();
        vector<vector<LL>> f(n, vector<LL>(m));
        LL ans = 0;
        for (int j = 0; j < m; j++) f[0][j] = p[0][j];
        for (int i = 1; i < n; i++) {
            priority_queue<LL> pq1;
            priority_queue<LL> pq2;
            for (int j = 0; j < m; j++) {
                pq1.push(f[i - 1][j] + j);
                f[i][j] = max(f[i][j], pq1.top() - j);
            }
            for (int j = m - 1; j >= 0; j--) {
                pq2.push(f[i - 1][j] - j);
                f[i][j] = max(f[i][j], pq2.top() + j);
            }
            for (int j = 0; j < m; j++) f[i][j] += p[i][j];
        }
        for (int j = 0; j < m; j++) ans = max(ans, f[n - 1][j]);
        return ans;
    }
};
