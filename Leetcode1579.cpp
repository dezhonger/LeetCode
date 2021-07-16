class Solution {
public:
    int find(vector<int>& f, int x) {
        return f[x] == x ? x : f[x] = find(f, f[x]);
    }
    void merge(vector<int>& f, int x, int y) {
        f[find(f, x)] = find(f, y);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> f1(n + 10), f2(n + 10);
        iota(f1.begin() + 1, f1.begin() + n + 1, 1);
        iota(f2.begin() + 1, f2.begin() + n + 1, 1);
        int ans = 0;
        for (auto& e: edges) {
            if (e[0] == 3) {
                if (find(f1, e[1]) != find(f1, e[2])) merge(f1, e[1], e[2]), merge(f2, e[1], e[2]);
                else ans++;
            }
        }
        for (auto& e : edges) {
            if (e[0] == 1) {
                if (find(f1, e[1]) != find(f1, e[2])) merge(f1, e[1], e[2]);
                else ans++;
            } else if (e[0] == 2) {
                if (find(f2, e[1]) != find(f2, e[2])) merge(f2, e[1], e[2]);
                else ans++;
            }
        }
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) if (f1[i] == i) a++;
        for (int i = 1; i <= n; i++) if (f2[i] == i) b++;
        if (a == 1 && b == 1) return ans;
        return -1;
    }
};
