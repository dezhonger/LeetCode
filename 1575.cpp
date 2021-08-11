
typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

const int N = 205;
int f[N][N];

class Solution {
public:
    // f[s][f]从s出发还剩下f汽油到达finish的方案数
    void add(int &x, int y, int mod = (int)1e9 + 7) {
        x += y;
        if (x > mod) x -= mod;
    }
    
    int cal(int pos, int fuel, vector<int>& locations, int& finish) {
        if (f[pos][fuel] != -1) return f[pos][fuel];
        
        //当前的汽油不足以到达终点
        int dis = abs(locations[pos] - locations[finish]);
        if (dis > fuel) return f[pos][fuel] = 0;
        
        f[pos][fuel] = 0;
        for (int i = 0; i < locations.size(); i++) {
            //枚举下一步走哪里
            if (i == pos) continue;
            int dis = abs(locations[pos] - locations[i]);
            if (dis > fuel) continue;
            add(f[pos][fuel], cal(i, fuel - dis, locations, finish));
        }
        
        // 如果当前就在终点，那么不再继续走也是一种方案
        if (pos == finish) add(f[pos][fuel], 1);
        return f[pos][fuel];
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(f, -1, sizeof f);
        // ans = f[start][fuel]
        cal(start, fuel, locations, finish);
        return f[start][fuel];
    }
};
