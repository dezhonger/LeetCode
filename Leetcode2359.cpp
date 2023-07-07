class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), ans = -1, minDis = INT_MAX;

        auto calcDis = [&](int node) -> vector<int> {
            vector<int> dis(n, INT_MAX);
            for (int d = 0; node >= 0 && dis[node] == INT_MAX; node = edges[node], d++)
                dis[node] = d;
            return dis;
        };

        auto d1 = calcDis(node1);
        auto d2 = calcDis(node2);

        for (int i = 0; i < n; i++)
        {
            int d = max(d1[i], d2[i]);
            if (d < minDis) minDis = d, ans = i;
        }
        return ans;
    }
};
