#define F first
#define S second

// __builtin_popcount(x)

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
    vector<int> f, frank;
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    
    void merge(int x, int y) {
        frank[find(y)] = max(frank[find(y)], frank[find(x)]);
        f[find(x)] = find(y);
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        
        
        vector<pair<int, pair<int, int>>> v;
        int n = matrix.size(), m = matrix[0].size();
        f = vector<int>(m * n + n + m);
        frank = vector<int>(m * n + n + m);
        iota(f.begin(), f.end(), 0);
        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<vector<int>> tmp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v.push_back({matrix[i][j], {i, j}});
            }
        }
        vector<int> rowRank(n);
        vector<int> colRank(m);
        sort(v.begin(), v.end());
        int sz = v.size();
        for (int i = 0; i < sz; i++) {
            int j = i;
            vector<int> row[n];
            vector<int> col[m];
            vector<pair<PII, PII>> p;
            while (j < sz && v[j].F == v[i].F) {
                int x = v[j].S.F, y = v[j].S.S;
                int mx = max(rowRank[x], colRank[y]);
                // for (int k = 0; k < n; k++) mx = max(mx, res[k][y]);
                // for (int k = 0; k < m; k++) mx = max(mx, res[x][k]);
                tmp[x][y] = mx + 1;
                // p.push_back({{tmp[x][y], x + y}, {x, y}});
                frank[x * m + y] = tmp[x][y];
                // merge(x * m + y, n * m + x);
                // merge(x * m + y, n * m + n + y);
                row[x].push_back(x * m + y);
                col[y].push_back(x * m + y);
                j++;
            }
            
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < row[i].size(); j++) merge(row[i][j-1], row[i][j]);
            }
            for (int i = 0; i < m; i++) {
                for (int j = 1; j < col[i].size(); j++) merge(col[i][j-1], col[i][j]);
            }
            
            
            for (int k = i; k < j; k++) {
                int x = v[k].S.F, y = v[k].S.S;
                res[x][y] = frank[find(x * m + y)];
                rowRank[x] = max(rowRank[x], res[x][y]);
                colRank[y] = max(colRank[y], res[x][y]);
            }
           
            
            i = j - 1;
        }
        return res;
    }
};
