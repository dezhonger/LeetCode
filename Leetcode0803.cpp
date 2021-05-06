#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0803.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-26 23:47:34

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;

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




const int N = 40010;
class Solution {
    public:
        int f[N], sz[N];
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        int find(int x) {
            if (x == f[x]) return x;
            return f[x] = find(f[x]);
        }

        bool merge(int a, int b) {
            int fa = find(a), fb = find(b);
            if (fa == fb) return false;
            f[fa] = fb; sz[fb] += sz[fa];
            return true;
        }

        vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> g = grid;
            for (auto p : hits) {
                int x = p[0], y = p[1];
                g[x][y] = 0;
            }
            int s = m * n;
            f[m * n] = m * n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int z = i * m + j;
                    sz[z] = g[i][j];
                    f[z] = z;
                }
            }


            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == 0) continue;
                    int z = i * m + j;
                    if (i == 0) {
                        //第一行与总源点相连
                        if (find(z) != find(s)) {
                            merge(z, s);
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && y >= 0 && x < n && y < m) {
                            if (g[x][y] == 0) continue;
                            merge(z, x * m + y);
                        }
                    }
                }
            }

            vector<int> res;
            for (int i = hits.size() - 1; i >= 0; i--) {
                auto p = hits[i];
                int x = p[0], y = p[1];
                if (grid[x][y] == 0) {
                    //这个地方没有砖块
                    res.pb(0);
                } else {
                    int sz1 = sz[find(s)];
                    g[x][y] = 1;
                    int zz = x * m + y;
                    sz[zz] = 1;
                    for (int k = 0; k < 4; k++) {
                        int xx = x + dx[k], yy = y + dy[k];
                        if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
                            if (g[xx][yy] == 0) continue;
                            merge(xx * m + yy, zz);
                        }
                    }
                    if (x == 0) merge(zz, s);

                    int sz2 = sz[find(s)];
                    debug(sz1, sz2);
                    res.pb(max(0, sz2 - sz1 - 1));
                }
            }
            reverse(res.begin(), res.end());
            return res;
        }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1}, {1},{1},{1},{1}};
    vector<vector<int>> h = {{3, 0}, {4, 0}, {1, 0}, {2, 0}, {0, 0}};
    auto res = s.hitBricks(v, h);
    debug(res);
    return 0;
}

