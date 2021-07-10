#define x first
#define y second

typedef pair<int, int> PII;

class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& s) {
        int n = g.size(), m = g[0].size(), INF = 1e8;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<PII> q;
        q.push({s[0], s[1]});
        dist[s[0]][s[1]] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i ++ ) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.' && dist[x][y] > dist[t.x][t.y] + 1) {
                    dist[x][y] = dist[t.x][t.y] + 1;
                    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) return dist[x][y];
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};
