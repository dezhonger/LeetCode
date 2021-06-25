class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();
        int maxV = 0, now = 0, wait = 0, all = 0, ans = -1;
        for (int i = 0; i < n || wait > 0; i++) {
            now = (i < n ? customers[i] : 0) + wait;
            int s = now >= 4 ? 4 : now;
            all += s;
            int profit = all * boardingCost - (i + 1) * runningCost;
            
            if (profit > maxV) {
                maxV = profit;
                ans = i + 1;
            }
            wait = now - s;
        }
        if (maxV <= 0) return -1;
        return ans;
    }
};
