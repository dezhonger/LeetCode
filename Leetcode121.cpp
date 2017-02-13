class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ans = 0, l = prices.size(), mi = prices[0];
        for(int i = 1; i < l; i++) {
            ans = max(ans, prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        return ans;
    }
};