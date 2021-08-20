template<typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size();
        // f[i][j] 考虑左边前i个人，右边以后连的人状态为j的最小代价
        vector<vector<int>> f(n + 1, vector<int>(1 << m, 1e8));
        int M = (1 << m);
        // 预处理代价
        vector<vector<int>> g(n + 1, vector<int>(1 << m, 0));
        for (int i = 1; i <= n; i++) {
            for (int s = 0; s < M; s++) {
                int c = 0;
                for (int j = 0; j < m; j++) {
                    if (s & (1 << j)) c += cost[i - 1][j];
                }
                g[i][s] = c;
            }
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s < M; s++) {
                //枚举上一行的状态，上一行是s的子集
                for (int sub = s; sub; sub = (sub - 1) & s) {
                    int last = s ^ sub;
                    upmin(f[i][s], f[i - 1][last] + g[i][sub]);
                }
                
                for (int j = 0; j < m; j++) upmin(f[i][s | (1 << j)], f[i - 1][s | (1 << j)] + g[i][1 << j]);
                
            }
        }

        return f[n][M - 1];
    }
};
