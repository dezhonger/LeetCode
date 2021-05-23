class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e8;
        vector<int> dist(n, INF), last;
        k++;
        dist[src] = 0;
        while (k--) {
            last = dist;
            for (auto& x: flights) {
                int a = x[0], b = x[1], c = x[2];
                dist[b] = min(dist[b], last[a] + c);
            }
        }
        if (dist[dst] == INF) dist[dst] = -1;
        return dist[dst];
    }
};
