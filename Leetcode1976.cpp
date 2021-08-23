typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

namespace X {
    const int N = 220, M = N * N;
    int n, m;
    int h[N], e[M], ne[M], idx;
    LL w[M];
    LL dist[N];
    bool st[N];
    vector<int> f;
    
    void init() {
        idx = 0;
        memset(h, -1, sizeof h);
        f = vector<int>(N, -1);
    }

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int cal(int u) {
        if (u == n) return f[u] = 1;
        if (f[u] != -1) return f[u];
        int ans = 0;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            ans += cal(j);
            ans %= mod;
        }
        return f[u] = ans;
    }
}


namespace Z{
    const int N = 220, M = N * N;
    int n, m;
    int h[N], e[M], ne[M], idx;
    LL w[M];
    LL dist[N];
    bool st[N];
    
    void init() {
        idx = 0;
        memset(h, -1, sizeof h);
    }

    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }

    void spfa() {
        memset(dist, 0x3f, sizeof dist);
        queue<int> q;
        q.push(0);
        st[0] = true;
        dist[0] = 0;
        while (q.size()) {
            int t = q.front();
            q.pop();
            st[t] = false;
            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    if (!st[j]) {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }
    }
};

class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {
        Z::init();
        for(auto& e: roads) {
            int x = e[0], y = e[1], z = e[2];
            Z::add(x, y, z);
            Z::add(y, x, z);
        }
        Z::spfa();
        
        X::init();
        X::n = n - 1;
        for(auto& e: roads) {
            int x = e[0], y = e[1], z = e[2];
            if (Z::dist[x] > Z::dist[y] && Z::dist[x] - Z::dist[y] == z) {
                X::add(y, x);
            }
            
            if (Z::dist[x] < Z::dist[y] && Z::dist[y] - Z::dist[x] == z) {
                X::add(x, y);
            }
        }
        
        return X::cal(0);
    }
};
