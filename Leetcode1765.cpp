class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    vector<vector<int>> h;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        n = isWater.size(), m = isWater[0].size();
        h = vector<vector<int>>(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                    h[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (q.size()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = cur.first + dx[i], y = cur.second + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && h[x][y] == -1) {
                    q.push({x, y});
                    h[x][y] = h[cur.first][cur.second] + 1;
                    
                }
            }
        }
        return h;
    }
};
