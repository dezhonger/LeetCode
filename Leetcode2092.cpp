class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> known(n);
        known[0] = true;
        known[firstPerson] = true;
  
        int maxT = 0;
        for (auto &meeting : meetings)
            maxT = max(maxT, meeting[2]);
        vector<vector<pair<int, int>>> time(maxT + 1);
        for (auto &meeting : meetings)
            time[meeting[2]].emplace_back(meeting[0], meeting[1]);
        
        vector<vector<int>> adj(n);
        for (int i = 1; i <= maxT; ++i) {
            if (time[i].empty())
                continue;
            
            unordered_set<int> vis;
            queue<int> q;
            for (auto &[u, v] : time[i]) {
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
                if (known[u] && !vis.count(u)) {
                    vis.insert(u);
                    q.push(u);
                }
                if (known[v] && !vis.count(v)) {
                    vis.insert(v);
                    q.push(v);
                }
            }
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!vis.count(v)) {
                        known[v] = true;
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
            
            for (auto &[u, v] : time[i]) {
                adj[u].clear();
                adj[v].clear();
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (known[i])
                ans.push_back(i);
        return ans;
    }
};
