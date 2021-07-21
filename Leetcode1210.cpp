#define F first
#define S second
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef long long LL;

int mod = (int)1e9 + 7;

template<typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    const int N = 10010;
    inline int get(int x, int y) {
        return x * m + y;
    }
    
    inline int get(int x, int y, int w, int z) {
        return get(x, y) * N + get(w, z);
    }
    
    inline vector<int> get(int val) {
        int a = val / N, b = val % N;
        return {a / m, a % m, b / m, b % m};
    }
    
    int minimumMoves(vector<vector<int>>& g) {
        n = g.size(), m = g[0].size();
        queue<pair<int, int>> q;
        int c = get(0, 1, 0, 0);
        q.push({c, 0});
        unordered_set<int> us;
        us.insert(c);
        int dd = get(n - 1, m - 1, n - 1, m - 2);
        while (q.size()) {
            auto cur = q.front();
            q.pop();
            if (dd == cur.F) return cur.S;
            auto abcd = get(cur.F);
            int step = cur.S;
            int a = abcd[0], b = abcd[1], c = abcd[2], d = abcd[3];
            for (int i = 0; i < 4; i++) {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && get(x, y) != get(c, d)) {
                    if ((dx[i] == 0 && a == c) || (dy[i] == 0 && b == d)) {
                        int nc = get(x, y, a, b);
                        if (!us.count(nc)) {
                            q.push({nc, step + 1});
                            us.insert(nc);
                        } 
                    }
                }
            }
            
            
            if (a == c && a + 1 < n && !g[a + 1][b] && !g[c + 1][d]) {
                //水平且下边的两个是空格子
                {
                    int nc = get(c + 1, d, c, d);
                    if (!us.count(nc)) {
                        q.push({nc, step + 1});
                        us.insert(nc);
                    }
                }
                {
                    int nc = get(a + 1, b, c + 1, d);
                    if (!us.count(nc)) {
                        q.push({nc, step + 1});
                        us.insert(nc);
                    }
                }
            }
            
            if (b == d && b + 1 < m && !g[a][b + 1] && !g[c][d + 1]) {
                //数值且右边的两个是空格子
                {
                    int nc = get(c, d + 1, c, d);
                    if (!us.count(nc)) {
                        q.push({nc, step + 1});
                        us.insert(nc);
                    }
                }
                {
                    int nc = get(a, b + 1, c, d + 1);
                    if (!us.count(nc)) {
                        q.push({nc, step + 1});
                        us.insert(nc);
                    }
                }
            }
        }
        return -1;
    }
};
