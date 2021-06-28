
typedef long long LL;
const int N = 100005;
int mod = (int)1e9 + 7;

class Solution {
public:
    
    int h[N], ne[N], e[N], idx;
    int sz[N], dp[N];
    LL f[N], g[N];
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    
    LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    
    LL dfs(int u) {
        sz[u] = 0;
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            LL d = dfs(v);
            sz[u] += sz[v];
        }
        dp[u] = f[sz[u]];
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            dp[u] = (dp[u] * g[sz[v]] % mod) * dp[v] % mod;
        }
        sz[u]++;
        return dp[u];
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        idx = 0;
        memset(h, -1, sizeof h);
        int n = prevRoom.size();
        f[0] = g[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i % mod;
            g[i] = powmod(f[i], mod - 2);
        }
        for (int i = 1; i < n; i++) {
            add(prevRoom[i], i);
        }
        dfs(0);
        return dp[0];
    }
};
