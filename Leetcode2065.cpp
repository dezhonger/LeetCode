class Solution {
public:
    int ans = 0;
    
    vector<int> values;
    vector<vector<pair<int, int>>> g;
    void dfs(int u, int time, int value, int maxTime, vector<int> &v)
    {
        
        if (u == 0) ans = max(ans, value);
        for (auto& e: g[u])
        {
            if (time + e.second <= maxTime)
            {
                if (!v[e.first]) {
                    v[e.first] = 1;
                    dfs(e.first, time + e.second, value + values[e.first], maxTime, v);
                    v[e.first] = 0;
                }
                else dfs(e.first, time + e.second, value, maxTime, v);
            } 
        }
    }

    int maximalPathQuality(vector<int>& vv, vector<vector<int>>& edges, int maxTime) {
        int n = vv.size();
        values = vv;
        g = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        for (auto& e: edges) {
           g[e[0]].push_back({e[1], e[2]});
           g[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> v(n, 0);
        v[0] = 1;
        ans = 0;
        dfs(0, 0, values[0], maxTime, v);
        return ans;
    }
};
