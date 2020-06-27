#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define Debug(x) cout<<#x<<"="<<x<<endl;


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int mod = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;
LL powmod (LL a, LL b) {
    LL res = 1;
    a %= mod;
    assert (b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
LL gcd (LL a, LL b) {
    return b ? gcd (b, a % b) : a;
}

class Solution {
//最小生成树算法。
//
//首先使用最小生成树算法得到最小生成树的路径和min_cost。
//
//如何判断一条边是不是关键边：将这条边从路径中去除，然后利用最小生成树算法求路径和，如果路径和大于min_cost或者不连通，
//那么这条边就是关键边。
//
//如何判断一条边为伪关键边：首先调用上面判断其是不是关键边，如果去除之后路径和不变，则说明其可以没有。那么怎么判断它可能会出现在
//某些最小生成树呢？只需要一开始将就这条边加入到最小生成树中，然后使用算法求路径和。如果路径和等于min_cost，则其就是伪关键边，否则就不是。


    pair<int, pair<int, int>> pp[205], p[205];
    int fa[105], m;

    int Find (int x) {
        return x == fa[x] ? x : (fa[x] = Find (fa[x]));
    }

    bool Union (int x, int y) {
        int u = Find (x);
        int v = Find (y);
        if (u == v) return false;
        fa[u] = v;
        return true;
    }

    //剔除第x条边, 求MST
    int kruskal (int x, int n) {
        int cnt = n;
        int cost = 0, tot = 0;
        for (int i = 0; i < m; i++) {
            if (i != x) p[tot++] = pp[i];
        }
        for (int i = 0; i < n; i++) fa[i] = i;
        sort (p, p + tot);
        for (int i = 0; i < tot; i++) {
            if (Union (p[i].S.F, p[i].S.S)) {
                cnt--;
                cost += p[i].F;
            }
        }
        //求出了MST的权值
        if (cnt == 1) return cost;
        //图不连通
        return INT_MAX;
    }

    int kruskal2 (int x, int n) {
        int cnt = n;
        int cost = 0, tot = 0;
        for (int i = 0; i < n; i++) fa[i] = i;

        for (int i = 0; i < m; i++) {
            if (i != x) p[tot++] = pp[i];
            else cost += pp[i].F, Union(pp[i].S.F, pp[i].S.S), --cnt;
        }
        sort (p, p + tot);
        for (int i = 0; i < tot; i++) {
            if (Union (p[i].S.F, p[i].S.S)) {
                cnt--;
                cost += p[i].F;
            }
        }
        return cnt == 1 ? cost : INT_MAX;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges (int n, vector<vector<int>>& edges) {
        vector<int> key, nkey;
        m = edges.size();
        for (int i = 0; i < m; i++) {
            pp[i].F = edges[i][2];
            pp[i].S.F = edges[i][0];
            pp[i].S.S = edges[i][1];
        }
        int res = kruskal(-1, n);
        for (int i = 0; i < m; i++) {
            if (kruskal(i, n) != res) key.pb(i);
            else if (kruskal2(i, n) == res) nkey.push_back(i);
        }

        vector<vector<int>> result;
        result.push_back(key);
        result.push_back(nkey);
        return result;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}
