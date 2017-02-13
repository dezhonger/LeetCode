package p1107.p20170213.stock;

/**
 * Created by dezhonger on 2017/2/13.
 * http://bookshadow.com/weblog/2015/02/18/leetcode-best-time-to-buy-and-sell-stock-iv/
 */
public class Leetcode188 {
	public int maxProfit(int k, int[] prices) {
		int len = prices.length;
		if(k > len / 2) {
			return cal(prices);
		}
		int[] dp = new int[k * 2 + 1];
		dp[0] = 0;
		int[] sign = new int[2];
		sign[0] = 1;
		sign[1] = -1;
		for(int i = 1; i < dp.length; i++) dp[i] = Integer.MIN_VALUE;
		for(int i = 0; i < len; i++) {
			for(int j = Math.min(2 * k, i + 1); j > 0; j--) {
				dp[j] = Math.max(dp[j], dp[j - 1] + prices[i] * sign[j % 2]);
			}
		}

		int ans = 0;
		for(int i = 0; i < dp.length; i++) {
			ans = Math.max(ans, dp[i]);
		}
		System.out.println(ans);
		return ans;
	}

	public int cal(int[] a) {
		int ans = 0;
		for(int i = 1; i < a.length; i++) {
			if(a[i] > a[i - 1]) {
				ans += a[i] - a[i - 1];
			}
		}
		return ans;
	}

	public static void main(String[] args) {
		new Leetcode188().maxProfit(1, new int[]{1, 2});
	}
}
