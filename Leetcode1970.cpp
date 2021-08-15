int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int n, m;
    vector<int> f;
    inline int get(int a, int b) {
        return a * m + b;
    }
    
    void merge(int a, int b) {
        f[find(a)] = find(b);
    }
    
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        this -> n = row;
        this -> m = col;
        f = vector<int>(n * m + 2);
        // 首行前面的一个位置和末行后面的一个位置
        int s = n * m, t = s + 1;
        vector<vector<int>> g(n, vector<int>(m, 1));
        for (int i = 0; i < n * m + 2; i++) f[i] = i;
        for (int i = n * m -1; i >= 0; i--) {
            int a = cells[i][0], b = cells[i][1];
            a--, b--;
            int c = get(a, b);
            g[a][b] = 0;
            if (a == 0) merge(c, s);
            if (a == n - 1) merge(c, t);
            for (int j = 0; j < 4; j++) {
                int x = a + dx[j], y = b + dy[j];
                if (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == 0) {
                    merge(c, get(x, y));
                }
            }
            if (find(s) == find(t)) {
                return i;
            }
        }
        // cannot reach here
        return -1;
    }
};
