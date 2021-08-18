class Solution {
public:
    vector<int> f;
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        f = vector<int>(n);
        iota(f.begin(), f.end(), 0);
        for (auto&e: edges) {
            int u = e[0], v = e[1];
            f[find(u)] = find(v);
            if (find(start) == find(end)) return 1;
        }
        return find(start) == find(end);
    }
};
