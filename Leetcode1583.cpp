

class Solution {
public:
    int nn;
    vector<vector<int>> p;
    bool check(int a, int b, int c) {
        int idx0 = -1, idx1 = -1;
        for (int i = 0; i < nn - 1; i++) {
            if (p[a][i] == b) idx0 = i;
            if (p[a][i] == c) idx1 = i;
            if (idx0 < 0 && idx1 >= 0) return false;
            if (idx0 >= 0 && idx1 < 0) return true;
        }
        return idx0 < idx1;
    }

    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int m = pairs.size(), res = 0;
        nn = n;
        p = preferences;
        vector<int> st(n);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int x = pairs[i][0];
                int y = pairs[i][1];
                int u = pairs[j][0];
                int v = pairs[j][1];
                if (!st[x] && ((check(x, u, y) && check(u, x, v)) || (check(x, v, y) && check(v, x, u)))) res++, st[x] = 1;
                if (!st[y] && ((check(y, u, x) && check(u, y, v)) || (check(y, v, x) && check(v, y, u)))) res++, st[y] = 1;
                if (!st[u] && ((check(u, x, v) && check(x, u, y)) || (check(u, y, v) && check(y, u, x)))) res++, st[u] = 1;
                if (!st[v] && ((check(v, x, u) && check(x, v, y)) || (check(v, y, u) && check(y, v, x)))) res++, st[v] = 1;
            }
        }
        return res;
    }
};
