class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, l = prices.size();
        for(int i = 1; i < l; i++) {
            if(prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};
