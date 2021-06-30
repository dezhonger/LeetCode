class Solution {
public:
    int n, m;
    int go(int x, int y, vector<vector<int>>& g) {
        if (x == n) return y;
        if (g[x][y] == 1 && y < m - 1 && g[x][y + 1] == 1) return go(x + 1, y + 1, g);
        if (g[x][y] == -1 && y > 0 && g[x][y - 1] == -1) return go(x + 1, y - 1, g);
        return -1;
    }

    vector<int> findBall(vector<vector<int>>& g) {
        n = g.size(), m = g[0].size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = go(0, i, g);
        }
        return res;
    }
};
