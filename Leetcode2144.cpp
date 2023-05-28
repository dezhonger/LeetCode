class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0, n = cost.size();
        for (int i = 0; i < (3 - n % 3); i++) cost.push_back(0);
        sort(cost.begin(), cost.end());
        n = cost.size();
        for (int i = 0; i < n; i++ ) cout << cost[i] << " ";
        for (int i = 2; i < n; i += 3) res += cost[i] + cost[i - 1];
        return res;
    }
};
