class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> anc(n);   // 存储每个节点祖先的辅助数组
        vector<vector<int>> e(n);   // 邻接表
        vector<int> indeg(n);   // 入度表
        // 预处理
        for (const auto& edge: edges) {
            e[edge[0]].push_back(edge[1]);
            ++indeg[edge[1]];
        }
        // 广度优先搜索求解拓扑排序
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: e[u]) {
                // 更新子节点的祖先哈希表
                anc[v].insert(u);
                for (int i: anc[u]) {
                    anc[v].insert(i);
                }
                --indeg[v];
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }
        // 转化为答案数组
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            for (int j: anc[i]) {
                res[i].push_back(j);
            }
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};
