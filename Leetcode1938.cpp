const int N = 100010 * 30;

int son[N][2], cnt[N], idx;
int ne[N << 1], h[N], e[N << 1], eidx;
vector<int> res;
class Solution {
public:

    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int v = x >> i & 1;
            if (!son[p][v]) son[p][v] = ++idx;
            p = son[p][v];
            cnt[p]++;
        }
        
    }
    
    void erase(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int v = x >> i & 1;
            p = son[p][v];
            cnt[p]--;
        }
        
    }
    
    int search(int x) {
        int p = 0, res = 0;
        for (int i = 30; i >= 0; i--) {
            int v = x >> i & 1;
            if (son[p][v ^ 1] && cnt[son[p][v ^ 1]]) {
                p = son[p][v ^ 1];
                res |= (1 << i);
            } else {
                p = son[p][v];
            }
        }
        return res;
    }

    void add(int a, int b) {
        e[eidx] = b, ne[eidx] = h[a], h[a] = eidx++;
    }
    
    void dfs(int u, int fa, vector<vector<pair<int, int>>>& q) {
        insert(u);
        
        for (auto& vp: q[u]) {
            int val = vp.first;
            res[vp.second] = search(val);
        }
        
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, u, q);
        }
        
        erase(u);
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = queries.size(), m = parents.size(), root;
        res = vector<int>(n);
        vector<vector<pair<int, int>>> q(m);
        for (int i = 0; i < n; i++) q[queries[i][0]].emplace_back(queries[i][1], i);
        eidx = 0;
        memset(h, -1, sizeof h);
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == -1) {
                root = i;
            } else {
                add(parents[i], i);
            }
        }
        
        idx = 0;
        memset(son, 0, sizeof son);
        dfs(root, -1, q);
        
        return res;
    }
};
