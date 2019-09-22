public class Leetcode0123 {
    public int maxProfit(int[] prices) {
        if(prices.length < 2) return 0;
        int l = prices.length;
        int[] dp1 = new int[l];
        int[] dp2 = new int[l];
        int mi = prices[0];
        dp1[0] = 0;
        for(int i = 1; i < l; i++) {
            dp1[i] = Math.max(prices[i] - mi, dp1[i-1]);
            mi = Math.min(mi, prices[i]);
        }
        int ma = prices[l-1];
        dp2[l-1] = 0;
        for(int i = l - 2; i >= 0; i--) {
            dp2[i] = Math.max(ma - prices[i], dp2[i+1]);
            ma = Math.max(ma, prices[i]);
        }
        int ans = 0;
        for(int i = 0; i < l; i++) {
            ans = Math.max(ans, dp1[i] + dp2[i]);
        }
        System.out.println(ans);
        return ans;
    }

    public static void main(String[] args) {
        new Solution().maxProfit(new int[]{6,1,3,2,4,7});
    }
}
