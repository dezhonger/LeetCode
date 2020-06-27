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
//��С�������㷨��
//
//����ʹ����С�������㷨�õ���С��������·����min_cost��
//
//����ж�һ�����ǲ��ǹؼ��ߣ��������ߴ�·����ȥ����Ȼ��������С�������㷨��·���ͣ����·���ʹ���min_cost���߲���ͨ��
//��ô�����߾��ǹؼ��ߡ�
//
//����ж�һ����Ϊα�ؼ��ߣ����ȵ��������ж����ǲ��ǹؼ��ߣ����ȥ��֮��·���Ͳ��䣬��˵�������û�С���ô��ô�ж������ܻ������
//ĳЩ��С�������أ�ֻ��Ҫһ��ʼ���������߼��뵽��С�������У�Ȼ��ʹ���㷨��·���͡����·���͵���min_cost���������α�ؼ��ߣ�����Ͳ��ǡ�


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

    //�޳���x����, ��MST
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
        //�����MST��Ȩֵ
        if (cnt == 1) return cost;
        //ͼ����ͨ
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
