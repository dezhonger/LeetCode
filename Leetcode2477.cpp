class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> e[n];
        for (auto &road : roads) e[road[0]].push_back(road[1]), e[road[1]].push_back(road[0]);

        long long ans = 0;
        // DFS 统计子树大小，同时统计答案
        function<int(int, int)> dfs = [&](int x, int fa) {
            int ret = 1;
            for (int y : e[x]) if (y != fa) {
                int t = dfs(y, x);
                ans = ans + (t + seats - 1) / seats;
                ret += t;
            }
            return ret ;
        };

        dfs(0, -1);
        return ans;
    }
};
