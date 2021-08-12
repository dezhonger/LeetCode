const int N = 50010, M = N * 2, P = 17;
//建图
int h[N], e[M], ne[M], idx;
//倍增
int depth[N], fa[N][P];
//bfs求的时候用的
int q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(int root)
{
    memset(depth, 0x3f, sizeof depth);
    //注意节点编号从1开始
    depth[0] = 0, depth[root] = 1;
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q[ ++ tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= P - 1; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = P - 1; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = P - 1; k >= 0; k -- )
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        memset(h, -1, sizeof h);
        memset(fa, 0, sizeof fa);
        idx = 0;
        int root;
        for (int i = 0; i < n; i++) {
            int a = i + 1, b = parent[i] + 1;
            if (b == 0) root = a;
            add(a, b), add(b, a);
        }
        bfs(root);
    }
    
    int getKthAncestor(int node, int k) {
        //node的k级祖先
        node++;
        for (int i = P - 1; node && i >= 0; i--) {
            if (k & (1 << i)) {
                node = fa[node][i];
            }
        }
        if (node == 0) return -1;
        return node - 1;
    }
};
