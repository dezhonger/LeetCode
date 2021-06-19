const int N = 40010;
int h[N], e[N], ne[N], idx;
double w[N], dist[N];
bool st[N];
int sta, ed, n;
void add(int a, int b, double c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
    fill(dist, dist + n, 0);
    //for (int i = 0; i < n; i++) dist[i] = 0;
    queue<int> q;
    q.push(sta);
    st[sta] = true;
    dist[sta] = 1.0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[t] * w[i]) {
                dist[j] = dist[t] * w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}


class Solution {
public:
    
    double maxProbability(int _n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        memset(h, -1, sizeof h);
        idx = 0;
        sta = start, ed = end, n =  _n;
        for (int i = 0; i < succProb.size(); i++) {
            auto x = edges[i];
            add(x[0], x[1], succProb[i]);
            add(x[1], x[0], succProb[i]);
        }
        spfa();
        return dist[end];
    }
};
