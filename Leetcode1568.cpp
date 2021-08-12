#include <bits/stdc++.h>

using namespace std;


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
 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
 
void my_assert(bool x) {
  if (!x) {
    cout << "NO" << '\n';
    exit(0);
  }
}



const int N = 1005, M = 1000010;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt;
vector<int> dcc[N];
bool cut[N];
int root;


void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u;

    if (u == root && h[u] == -1)
    {
        dcc_cnt ++ ;
        dcc[dcc_cnt].push_back(u);
        return;
    }

    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (dfn[u] <= low[j])
            {
                cnt ++ ;
                if (u != root || cnt > 1) cut[u] = true;
                ++ dcc_cnt;
                int y;
                do {
                    y = stk[top -- ];
                    dcc[dcc_cnt].push_back(y);
                } while (y != j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u] = min(low[u], dfn[j]);
    }
}

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        //初始化变量
        idx = timestamp = top = dcc_cnt = 0;
        memset(h, -1, sizeof h);
        memset(dfn, 0, sizeof dfn);
        memset(cut, 0, sizeof cut);
        
        //建图
        unordered_map<int, int> mp;
        int nn = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) mp[i * grid[0].size() + j] = ++nn;
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1}; 
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int u = mp[i * grid[0].size() + j];
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1) {
                            int v = mp[x * grid[0].size() + y];
                            add(u, v);
                        }
                    }
                }
            }
        }
        int ss = 0;
        for (root = 1; root <= nn; root ++ )
            if (!dfn[root])
                ss++, tarjan(root);
        // 没有岛屿
        if (nn == 0) return 0;
        // 只有一个岛屿
        if (nn == 1) return 1;
        
        if (ss > 1) return 0;
        
        // 求一下割点个数
        int cutPointNum = 0;
        for (int i = 1; i <= nn; i++) {
            if (cut[i]) cutPointNum++;
        }
        // 存在割点，只要删除一个割点岛屿的连通块数量就会变多
        if (cutPointNum > 0) return 1;
        
        // 没有割点，稍微思考一下，只要把角落里的两个斜着的删掉就会多一个连通块
        return 2;
        
    }
};


