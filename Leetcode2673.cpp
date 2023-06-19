class Solution {
public:
    int minIncrements(int n, vector<int> &cost) {
        int ans = 0;
        for (int i = n / 2; i; i--) { 
            // 下标从0开始
            ans += abs(cost[i * 2 - 1] - cost[i * 2]);
            cost[i - 1] += max(cost[i * 2 - 1], cost[i * 2]); // 累加路径和
        }
        return ans;
    }
};
