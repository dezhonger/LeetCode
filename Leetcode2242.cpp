class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto& e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back({-scores[y], y});
            g[y].push_back({-scores[x], x});
        }
        for (auto& item: g) {
            if (item.size() > 3) {
                //第三个元素在正确的位置，其他的满足左边都第三个，右边都大于第三个元素
                nth_element(item.begin(), item.begin() + 3, item.end());
                //只保留前三大的
                item.resize(3);
            }
        }
        int ans = -1;
        for (auto& e: edges) {
            int x = e[0], y = e[1];
            for (auto& [v1, node1]: g[x]) {
                for (auto& [v2, node2]: g[y]) {
                    if (y != node1 && x != node2 && node1 != node2) {
                        ans = max(ans, scores[x] + scores[y] - v1 - v2);
                    }
                }
            }
        }
        return ans;
    }
};
