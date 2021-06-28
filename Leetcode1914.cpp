class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();
        for (int i = 0, a = n - 1, b = m - 1;i < min(n, m) / 2 ;i++, a--, b--) {
            int x = i, y = i;
            int cr = b - i, cc = a - i;
            vector<int> v;
            for (int k = 0; k < cr; k++) v.push_back(g[x][y++]);
            for (int k = 0; k < cc; k++) v.push_back(g[x++][y]);
            for (int k = 0; k < cr; k++) v.push_back(g[x][y--]);
            for (int k = 0; k < cc; k++) v.push_back(g[x--][y]);
            int sz = v.size(), j = k % sz;
            for (int k = 0; k < cr; k++) g[x][y++] = v[(j++) % sz];
            for (int k = 0; k < cc; k++) g[x++][y] = v[(j++) % sz];
            for (int k = 0; k < cr; k++) g[x][y--] = v[(j++) % sz];
            for (int k = 0; k < cc; k++) g[x--][y] = v[(j++) % sz];
            
        }
        return g;
    }
};
