int f[10010];

class Solution {
public:
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int m = queries.size();
        for (int i = 0; i <= n; i++) f[i] = i;
        vector<bool> ans(m, false);
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                f[find(i)] = find(j);
            }
        }
        
        for (int i = 0; i < m; i++) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = (find(u) == find(v));
        }
        return ans;
    }
};
