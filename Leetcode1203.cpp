class Solution {
public:

    vector<int> topSort(vector<vector<int>> &g, vector<int> &in, vector<int> &id) {
        vector<int> ans;
        queue<int> q;
        for (int x: id) if (!in[x]) q.push(x);
        while (q.size()) {
            int c = q.front();
            q.pop();
            ans.push_back(c);
            for (int x: g[c]) {
                if (--in[x] == 0) q.push(x);
            }
        }
        if (ans.size() == id.size()) return ans;
        return vector<int>{};
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int maxZ = m + n;
        vector<vector<int>> groupItem(maxZ);
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) group[i] = m++;
            groupItem[group[i]].emplace_back(i);
        }
        vector<vector<int>> g1(maxZ);
        vector<vector<int>> g2(n);
        
        vector<int> in1(maxZ);
        vector<int> in2(n);
        
        for (int i = 0; i < n; i++) {
            int group1 = group[i];
            for (int x: beforeItems[i]) {
                int group2 = group[x];
                if (group1 == group2) {
                    //属于同一个组
                    in2[i]++;
                    g2[x].emplace_back(i);
                } else {
                    in1[group1]++;
                    g1[group2].emplace_back(group1);
                }
            }
        }
        
        vector<int> id(maxZ);
        iota(id.begin(), id.end(), 0);
        // 获取按照组来的拓扑排序
        auto gans = topSort(g1, in1, id);
        if (gans.size() == 0) return vector<int>{}; 
        
        
        vector<int> ans;
        for (int g: gans) {
            if (groupItem[g].size() == 0) continue;
            auto inans = topSort(g2, in2, groupItem[g]);
            if (inans.size() == 0) return vector<int>{};
            for (int x: inans) ans.emplace_back(x);
        }
        return ans;
    }
};
