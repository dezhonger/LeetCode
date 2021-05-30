class Solution {
public:
    set<int> s;
    int n, m;
    int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, -1, 1};

    vector<vector<int>> g;
    int cal(int x, int y, int k) {
        if (k == 1) return g[x][y];
        int cnt = k * 4, res = 0, nx, ny;
        for (int d = 0; d < 4; d++) {
            for (int c = 1; c < k; c++) {
                x = x + dx[d], y = y + dy[d];
                if (x < 0 || y < 0 || x >= n || y >= m) return -1;
                res += g[x][y];
            }
        }
        return res;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size(), m = grid[0].size();
        int d = (min(n, m) + 1) / 2;
        s.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 1; k <= d; k++) {
                    int res = cal(i, j, k);
                    if (res == -1) break;
                    s.insert(res);
                }
            }
        }
        vector<int> ans;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            ans.push_back(*it);
            if (ans.size() >= 3) break;
        }
        return ans;
    }
};
