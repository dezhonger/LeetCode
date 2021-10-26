const int N = 40010;

int h[N], ne[N], e[N], idx;
void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        memset(h, -1, sizeof h);
        idx = 0;
        for (auto& e : edges) {
            add(e[0], e[1]);
            add(e[1], e[0]);
        }
        int min1 = INT_MAX, min2 = INT_MAX;
        queue<pair<int, int>> q;
        q.push({0, 1});
        vector<int> v1(n + 1, INT_MAX), v2(n + 1, INT_MAX);
        v1[0] = v2[0] = 0;
        while(q.size()) {
            auto p = q.front();
            q.pop();
            int t = p.first, pos = p.second;
            if (pos == n && v2[n] != INT_MAX && v2[n] > v1[n]) {
                return v2[n];
            }            
            if (t % (2 * change) < change) {
                // green
                int net = t + time;
                for (int i = h[pos]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (net >= v2[j]) continue;
                    if (net < v1[j]) v2[j] = v1[j], v1[j] = net;
                    else if (net > v1[j] && net < v2[j]) v2[j] = net;
                    q.push({net, j});
                }
            } else {
                int net = t + 2 * change - t % (2 * change) + time;
                // red
                for (int i = h[pos]; ~i; i = ne[i]) {
                    int j = e[i];
                    if (net >= v2[j]) continue;
                    if (net < v1[j]) v2[j] = v1[j], v1[j] = net;
                    else if (net > v1[j] && net < v2[j]) v2[j] = net;
                    q.push({net, j});
                }
            }
        }
        // cannot reach here
        return -1;
    }
};
