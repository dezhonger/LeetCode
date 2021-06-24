const int N = 105;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> d(n);
        int g[N][N];
        memset(g, 0, sizeof g);
        for (auto e: roads) {
            d[e[0]]++;
            d[e[1]]++;
            g[e[0]][e[1]] = g[e[1]][e[0]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, d[i] + d[j] - g[i][j]);
            }
        }
        return ans;
        
    }
};
