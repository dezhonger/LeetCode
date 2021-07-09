class Solution {
public:
    const int N = 61;
    
    vector<vector<int>> graph;
    vector<int> in;
    vector<bool> exist;
    //不同的颜色总数
    int s;
    int n, m;
    void cal(int c, vector<vector<int>>& g) {
        int x1, y1, x2, y2;
        x1 = y1 = INT_MAX;
        x2 = y2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == c) {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        // 没有这个颜色的
        if (x1 == INT_MAX) return ;
        exist[c] = true;
        s++;
        // 枚举这个矩形内的的其他颜色：意义是，先涂完颜色c后，再去途其他颜色
        vector<bool> v(N);
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                int u = g[i][j];
                if (u != c && !v[u]) {
                    int u = g[i][j];
                    graph[c].push_back(u);
                    in[u]++;
                    v[u] = true;
                }
            }
        }
    }

    bool isPrintable(vector<vector<int>>& g) {
        n = g.size(), m = g[0].size();
        s = 0;
        exist = vector<bool>(N, false);
        in = vector<int>(N, 0);
        graph = vector<vector<int>>(N, vector<int>());
        for (int i = 1; i < N; i++) cal(i, g);
        queue<int> q;
        for (int i = 1; i < N; i++) {
            if (exist[i] && !in[i]) q.push(i);
        }
        while (q.size()) {
            int c = q.front();
            q.pop();
            s--;
            for (int u: graph[c]) {
                if (--in[u] == 0) q.push(u);
            }
        }
        return s == 0;
    }
};
