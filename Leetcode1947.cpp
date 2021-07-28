const int N = 20, M = 200, INF = 1e8;

int S, T;
int h[N], e[M], f[M], w[M], ne[M], idx;
int q[N], d[N], pre[N], incf[N];
bool st[N];

void add(int a, int b, int c, int d)
{
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx ++ ;
}

bool spfa()
{
    int hh = 0, tt = 1;
    memset(d, 0x3f, sizeof d);
    memset(incf, 0, sizeof incf);
    q[0] = S, d[S] = 0, incf[S] = INF;
    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (f[i] && d[ver] > d[t] + w[i])
            {
                d[ver] = d[t] + w[i];
                pre[ver] = i;
                incf[ver] = min(f[i], incf[t]);
                if (!st[ver])
                {
                    q[tt ++ ] = ver;
                    if (tt == N) tt = 0;
                    st[ver] = true;
                }
            }
        }
    }

    return incf[T] > 0;
}

void EK(int& flow, int& cost)
{
    flow = cost = 0;
    while (spfa())
    {
        int t = incf[T];
        flow += t, cost += t * d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1])
        {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
}

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        idx = 0;
        memset(h, -1, sizeof h);
        
        int n = students.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int c = 0;
                for (int k = 0; k < students[i].size(); k++) {
                    if (students[i][k] == mentors[j][k]) c++;
                }
                add(i, j + n, 1, -c);
            }
        }
        
        S = 2 * n, T = 2 * n + 1;
        for (int i = 0; i < n; i++) add(S, i, 1, 0), add(i + n, T, 1, 0);
        int flow, cost;
        EK(flow, cost);
        return -cost;
    }
};
