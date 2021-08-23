#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)x.size())

// template<typename T, typename S>
// inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

// template<typename T, typename S>
// inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
void my_assert(bool x) {
  if (!x) {
    cout << "NO" << '\n';
    exit(0);
  }
}

// LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


template<typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }


#define F first
#define S second
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef long long LL;

int mod = (int)1e9 + 7;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
    inline int hash(int a, int b, int c, int d) {
        return a * 1000000 + b * 10000 + c * 100 + d;
    }
    int minPushBox(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        int tx, ty, sx, sy, bx, by;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (g[i][j] == 'T') tx = i, ty = j;
            else if (g[i][j] == 'B') bx = i, by = j;
            else if (g[i][j] == 'S') sx = i, sy = j;
        }
        // debug(tx, ty);
        // debug(bx, by);
        // debug(sx, sy);
        
        // 人和箱子的坐标
        queue<vector<int>> q;
        unordered_set<int> st;
        int hsh = hash(sx, sy, bx, by);
        st.insert(hsh);
        q.push({sx, sy, bx, by});
        unordered_map<int, int> dist;
        dist[hsh] = 0;
        int ans = INT_MAX;
        while (q.size()) {
            // 枚举人的四个方向
            auto cur = q.front();
            // debug(cur);
            q.pop();
            int oldh = hash(cur[0], cur[1], cur[2], cur[3]);
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i], ny = cur[1] + dy[i];
                // 枚举人走到下一个空的位置
                // debug(nx, ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                    (g[nx][ny] != '#' && !(nx == cur[2] && ny == cur[3]))) {
                        int hh = hash(nx, ny, cur[2], cur[3]);
                        if (st.find(hh) == st.end() || dist[oldh] < dist[hh]) {
                            st.insert(hh);
                            //只有人走，推动次数不变
                            dist[hh] = dist[oldh];
                            q.push({nx, ny, cur[2], cur[3]});
                        }
                }
                
                //要走的下一个位置就是箱子的位置
                if (nx == cur[2] && ny == cur[3]) {
                    // 箱子的下一个方向是空的
                    int nnx = nx + dx[i], nny = ny + dy[i];
                    if (nnx >= 0 && nnx < n && nny >= 0 && nny < m) {
                        // if (nnx == tx && nny == ty) return dist[oldh] + 1;
                        if (nnx == tx && nny == ty) ans = min(ans, dist[oldh] + 1);
                        else if (g[nnx][nny] != '#') {
                            int hh = hash(nx, ny, nnx, nny);
                            if (st.find(hh) == st.end() || dist[oldh] < dist[hh]) {
                                st.insert(hh);
                                dist[hh] = dist[oldh] + 1;
                                q.push({nx, ny, nnx, nny});
                            }
                        }
                    }
                }
            }
        }
        // debug(dist[hash(9, 3, 1, 4)]);
        // debug(dist[hash(0, 4, 1, 4)]);
        // debug(dist[hash(1, 4, 2, 4)]);
        // debug(dist[hash(2, 3, 2, 4)]);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution s;
    vector<vector<char>> v = {
        {'#','#','#','#','#','#'},
        {'#','T','#','#','#','#'},
        {'#','.','.','B','.','#'},
        {'#','.','#','#','.','#'},
        {'#','.','.','.','S','#'},
        {'#','#','#','#','#','#'}
    };
    
    vector<vector<char>> v2 = 
    {{'#','#','#','#','#','#'},
{'#','T','.','.','#','#'},
{'#','.','#','B','.','#'},
{'#','.','.','.','.','#'},
{'#','.','.','.','S','#'},
{'#','#','#','#','#','#'}};

    vector<vector<char>> v3 = 
{{'.','.','#','.','.','.','.','.','.','.'},
{'.','#','.','#','B','#','.','#','.','.'},
{'.','#','.','.','.','.','.','.','T','.'},
{'#','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','#'},
{'.','.','.','.','.','.','.','.','#','.'},
{'.','.','.','#','.','.','#','#','.','.'},
{'.','.','.','.','#','.','.','#','.','.'},
{'.','#','.','S','.','.','.','.','.','.'},
{'#','.','.','#','.','.','.','.','.','#'}};

    auto res = s.minPushBox(v3);
    debug(res);
    return 0;
};





















