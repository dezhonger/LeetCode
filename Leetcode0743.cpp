#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0743.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-22 20:04:45
//Last modified: 2021-05-22 20:14:45

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i <= (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;
#define Debug(x) cout<<#x<<"="<<x<<endl;

const int mod = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;

const int N = 105, M = 6010, INF = 0x3f3f3f3f;
int h[N], ne[M], e[M], w[M], idx;
int dist[N], st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa(int k) {
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    st[k] = 1;
    dist[k] = 0;
    q.push(k);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int u = e[i];
            if (dist[u] > dist[t] + w[i]) {
                dist[u] = dist[t] + w[i];
                if (!st[u]) {
                    st[u] = 1;
                    q.push(u);
                }
            }
        }
    }
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        idx = 0;
        for (auto& x: times) {
            int a = x[0], b = x[1], c = x[2];
            add(a, b, c);
        }
        spfa(k);
        int res = 0;
        for (int i = 1; i <= n; i++) res = max(res, dist[i]);
        if (res == INF) res = -1;
        return res;
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}
