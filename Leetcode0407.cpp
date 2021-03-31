#include <bits/stdc++.h>
using namespace std;

#define vi vector
#define C Cell
class Solution {
public:

    struct C {
        int h, x, y;
        bool operator> (const C& t) const {
            return h > t.h;
        }
    };
    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        //小根堆
        priority_queue<C, vi<C>, greater<C>> q;
        vi<vi<bool>> v(n, vi<bool>(m, false));
        for (int i = 0; i < n; i++) {
            q.push({h[i][0], i, 0});
            q.push({h[i][m - 1], i, m - 1});
            v[i][0] = true;
            v[i][m - 1] = true;
        }
        for (int j = 1; j + 1 < m; j++) {
            q.push({h[0][j], 0, j});
            q.push({h[n - 1][j], n - 1, j});
            v[0][j] = true;
            v[n - 1][j] = true;
        }
        int res = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while (q.size()) {
            C c = q.top();
            q.pop();
            //c.h从该点到所有边界的最小值(包含自己)
            res += c.h - h[c.x][c.y];
            for (int i = 0; i < 4; i++) {
                int x = c.x + dx[i], y = c.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && !v[x][y]) {
                    q.push({max(h[x][y], c.h), x, y});
                    v[x][y] = true;
                }
            }
        }
        return res;
    }
};


int main() {
    return 0;
}