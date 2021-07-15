class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<vector<int>> g2(n, vector<int>(n, 0));
        for (auto& e: edges) {
            e[0]--;
            e[1]--;
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
            g2[e[0]][e[1]] = g2[e[1]][e[0]] = 1;
        }
        
        int minD = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (g2[i][j] && g2[j][k] && g2[i][k]) {
                        int a = g[i].size() - 2;
                        int b = g[j].size() - 2;
                        int c = g[k].size() - 2;
                        minD = min(minD, a + b + c);
                    }
                }
            }
        }
        if (minD == INT_MAX) return -1;
        return minD;
    }
};
