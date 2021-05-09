#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1857.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-10 03:49:12
//Last modified: 2021-05-10 04:05:38

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

#define Debug(x) cout<<#x<<"="<<x<<endl;
const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int mod = int (1e9) + 7;
const double EPS = 1e-6;

const int N = 100010;
int h[N], ne[N], e[N], idx, in[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        memset(h, -1, sizeof h);
        memset(in, 0, sizeof in);
        idx = 0;
        for (auto& x: edges) {
            int a = x[0], b = x[1];
            in[b]++;
            add(a, b);
        }
        int n = colors.size();
        vector<int> p;
        queue<int> q;
        for (int i = 0; i < n; i++) if (!in[i]) q.push(i);
        while (q.size()) {
            int c = q.front();
            p.push_back(c);
            q.pop();
            for (int i = h[c]; ~i; i = ne[i]) {
                int u = e[i];
                if (--in[u] == 0) q.push(u);
            }
        }
        if (p.size() < n) return -1;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        int res = 0;
        for (int u: p) {
            int &f = dp[u][colors[u] - 'a'];
            f = max(f, 1);
            res = max(res, f);
            //update next node
            for (int i = h[u]; ~i; i = ne[i]) {
                int v = e[i];
                for (int j = 0; j < 26; j++) {
                    int nc = (colors[v] - 'a' == j) ? 1 : 0;
                    int& g = dp[v][j];
                    g = max(g, dp[u][j] + nc);
                    res = max(res, g);
                }
            }
        }
        return res;
    }
};



