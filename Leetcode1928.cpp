class Solution {
public:
    int s, n;
    vector<vector<pair<int, int>>> g;

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        n = passingFees.size();
        s = 0;
        g = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        vector<vector<int>> f(maxTime + 1, vector<int>(passingFees.size(), 1e8));
        f[0][0] = passingFees[0];
        for (auto x: edges) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        int ans = 1e8;
        for (int i = 1; i <= maxTime; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& [k, v]: g[j]) {
                    if (i - v >= 0) f[i][j] = min(f[i][j], f[i - v][k] + passingFees[j]);
                }
            }
            ans = min(ans, f[i][n - 1]);
        }
        if (ans < 1e8) return ans;
        return -1;
    }
};
