typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef long long LL;

int mod = (int)1e9 + 7;

LL f[1005][250];
bool g[250][250];

class Solution {
public:
    // vector<int> ccc(int m, int x) {
        // vector<int> s(m);
        // while (x) {
            // s.push_back(x % 3);
            // x /= 3;
        // }
        // return s;
    // }

    bool check(int m, int x) {
        vector<int> s(m, 0);
        int cc = 0;
        while (x) {
            s[cc++] = x % 3;
            x /= 3;
        }
    
        for (int i = 1; i < m; i++) {
            if (s[i] == s[i - 1]) return false;
        }
        return true;
    }

    vector<int> init(int m) {
        int p = 1;
        vector<int> state;
        for (int i = 0; i < m; i++) p *= 3;
        for (int i = 0; i < p; i++) {
            if (check(m, i)) state.push_back(i);
        }
        return state;
    }
    
    bool can(int s1, int s2, int m) {
        vector<int> sta1(m, 0);
        int cc = 0;
        while (s1) {
            sta1[cc++] = s1 % 3;
            s1 /= 3;
        }
        
        cc = 0;
    
        
        vector<int> sta2(m, 0);
        while (s2) {
            sta2[cc++] = s2 % 3;
            s2 /= 3;
        }
        
        
        // debug(s1, s2, m, sta1, sta2);
        for (int i = 0; i < m; i++) {
            if (sta1[i] == sta2[i]) return false;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        vector<int> state = init(m);
        for (int j: state) f[1][j] = 1;
        for (int j: state) for (int k: state) g[j][k] = can(j, k, m);
        for (int i = 2; i <= n; i++) {
            for (int j: state) {
                for (int k: state) {
                    if (g[j][k]) {
                        f[i][j] += f[i - 1][k];
                        f[i][j] %= mod;
                    }
                }
            }
        }
        LL res = 0;
        for (int j: state) {
            // debug(f[n][j]);
            res += f[n][j];
            res %= mod;
        }
        return res;
    }
};
