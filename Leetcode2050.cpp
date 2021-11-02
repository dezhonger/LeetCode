const int N = 50010;
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


class Solution {
public:
    vector<int> t;

    int dfs(int u, vector<int>& time) {
        if (t[u] != -1) return t[u];
        t[u] = time[u - 1];
        int y = 0;
        for (int i = h[u]; ~i; i = ne[i]) y = max(dfs(e[i], time), y);
        return t[u] += y;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        t = vector<int>(n + 1, -1);
        idx = 0;
        memset(h, -1, sizeof h);
        for (auto& e: relations) add(e[1], e[0]);
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dfs(i, time));
        return ans;
    }
};
