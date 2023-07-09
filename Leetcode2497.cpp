class Solution {
public:
    int maxStarSum(vector<int>& c, vector<vector<int>>& edges, int k) {
        int n = c.size();
        int res = INT_MIN;
        vector<vector<int>> g(c.size() + 10, vector<int>());
        for(int i = 0; i < edges.size(); i++){
            int x1 = edges[i][0];
            int x2 = edges[i][1];
            if (c[x2] >= 0) g[x1].push_back(c[x2]);
            if (c[x1] >= 0) g[x2].push_back(c[x1]);
        }
        for(int i = 0; i < n; i++){
            priority_queue<int> pq;
            for (int v: g[i]) pq.push(v);
            int size = min(int(pq.size()),k);
            int maxN = 0;
            while(size--) maxN += pq.top(), pq.pop();
            res = max(res, maxN + c[i]);
        }
        return res;
    }
};
