//https://www.acwing.com/solution/content/4124/
class Solution {
public:
    vector<int> f;
    
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //记录度数
        vector<int> d(n + 1, 0);
        //记录入点有两条边的点
        int g;
        for (auto x : edges) {
            d[x[1]]++;
            if (d[x[1]] == 2) g = x[1];
        }
        
        //并查集数组
        f = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++) f[i] = i;
        
        
        vector<int> t;
        for (int i = 0; i < n; i++) {
            vector<int> x = edges[i];
            int a = x[0], b = x[1];
            
            if (b == g) {
                //这种边先不加进去，最后再加
                t.push_back(a);
            } else {
                //在这种情况下都有环的话，删除一个就好了
                int fa = find(a);
                int fb = find(b);
                //加边之前已经在一个集合里了，那么再加就有环了
                if (fa == fb) return {a, b};
                f[fb] = fa;
            }
        }
        
        int fa = find(t[0]);
        int fb = find(g);
        if (fa == fb) return {t[0], g};
        return {t[1], g};
        
        
        
    }
};