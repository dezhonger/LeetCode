const int N = 6060;
class Solution {
public:
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int n = forbidden.size();
        vector<vector<int>> dist(N + 1, vector<int>(2, -1));
        for (int y: forbidden) dist[y][0] = dist[y][1] = 1e8;
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        while (q.size()) {
            auto cur = q.front();
            q.pop();
            if (cur.first == x) return dist[cur.first][cur.second];
            int nxt = cur.first + a;
            if (nxt <= N && dist[nxt][0] == -1) {
                dist[nxt][0] = dist[cur.first][cur.second] + 1;
                q.push({nxt, 0});
            }
            
            
            if (cur.second == 0) {
                // 上一步是前进来的
                int nxt = cur.first - b;
                if (nxt >= 0 && dist[nxt][1] == -1) {
                    dist[nxt][1] = dist[cur.first][cur.second] + 1;
                    q.push({nxt, 1});
                }
            }
        }
        return -1;
    }
};
