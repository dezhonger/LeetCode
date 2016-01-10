vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> ans;
    //vector<set<int>> g[n];
    set<int> g[n];
    if(n == 1) {ans.push_back(0); return ans;}
    for(unsigned int i = 0; i < edges.size(); i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        g[a].insert(b);
        g[b].insert(a);
    }
    vector<int> cur;
    vector<int> ne;
    for(int i = 0; i < n; i++) {
        if(g[i].size() == 1) {
            cur.push_back(i);
        }
    }
    while(1) {
        for(int node : cur) {
            for(int neighbor : g[node]) {
                g[neighbor].erase(node);
                if(g[neighbor].size() == 1) ne.push_back(neighbor);
            }
        }
        if(ne.empty()) return cur;
        cur = ne;
        ne.clear();
    }
   
}