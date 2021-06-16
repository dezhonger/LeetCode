class Solution {
public:

    vector<int> f;
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        f = vector<int>(n);
        int res = 0;
        vector<pair<int, pair<int, int>>> p;
        iota(f.begin(), f.end(), 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                p.push_back({dis, {i, j}});
            }
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < p.size(); i++) {
            auto node = p[i];
            int n1 = node.second.first, n2 = node.second.second;
            if (find(n1) != find(n2)) {
                res += node.first;
                f[find(n1)] = find(n2);
            }
        }
        return res;
    }
};
