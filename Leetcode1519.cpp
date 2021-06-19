const int N = 200010;
int h[N], ne[N], e[N], idx;
vector<int> res;
string l;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

vector<int> dfs(int u, int fa) {    
    vector<int> d(26, 0);
    d[l[u] - 'a']++;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue;
        auto c = dfs(v, u);
        for (int i = 0; i < 26; i++) d[i] += c[i];
    }
    res[u] = d[l[u] - 'a'];
    return d;
    
}

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        memset(h, -1, sizeof h);
        idx = 0;
        l = labels;
        res = vector<int>(n);
        for (auto& x : edges) {
            add(x[0], x[1]);
            add(x[1], x[0]);
        }
        
        dfs(0, -1);
        return res;
    }
};
