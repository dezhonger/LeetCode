//Çó¸î±ß
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


vector<vector<int>> v;
vector<vector<int>> ret;
vector<int> dfn, low;
int times;


void tarjan (int x, int parent) {
    dfn[x] = low[x] = ++times;
    for (int y : v[x]) {
        if (y == parent) continue;
        if (!dfn[y]) {
            tarjan (y, x);
            low[x] = min (low[x], low[y]);
            if (low[y] > dfn[x]) ret.push_back ({x, y});
        } else {
            low[x] = min (low[x], dfn[y]);
        }
    }
}


vector<vector<int>> criticalConnections (int n, vector<vector<int>>& connections) {
    v = vector<vector<int>> (n);
    dfn = low = vector<int> (n);
    times = 0;
    ret.clear();
    for (vector<int> e : connections) {
        v[e[0]].push_back (e[1]);
        v[e[1]].push_back (e[0]);
    }

    for (int i = 0; i < n ; i++) {
        if (!dfn[i]) tarjan (i, -1);
    }
    return ret;
}


int main() {
    return 0;
}
