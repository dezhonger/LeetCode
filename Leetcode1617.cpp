
const int N = 16, M = N << 1;
int h[N], e[M], ne[M], idx;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    int maxD = 0;
    // d[i]以i节点为根到叶子节点的最长长度
    vector<int> d;
    void dfs(int u, int fa) {
        // 以u为根到叶子节点的最大值和次大值
        int m1 = 0, m2 = 0;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, u);
            d[u] = max(d[u], d[j] + 1);
            if (d[j] + 1 > m1) m2 = m1, m1 = d[j] + 1;
            else if (d[j] + 1 > m2) m2 = d[j] + 1;
        }
        maxD = max(maxD, m1 + m2);
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        //考虑到边的给出方式，我们直接枚举边
        int m = edges.size();
        vector<int> ans(m);
        for (int i = 0; i < (1 << m); i++) {
            memset(h, -1, sizeof h);
            idx = 0;
            maxD = 0;
            d = vector<int>(n + 1, 0);
            int bian = 0;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    int x = edges[j][0], y = edges[j][1];
                    bian++;
                    add(x, y);
                    add(y, x);
                }
            }
            
            //统计点的数量，并随意选一个点作为根结点
            int c = 0, root = -1;
            for (int i = 1; i <= n; i++) {
                if (~h[i]) c++, root = i;
            }
            if (bian + 1 != c) {
                //不是一棵树
                continue;
            }
            dfs(root, -1);
            ans[maxD - 1]++;
        }
        return ans;
    }
};
