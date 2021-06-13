

/**
 * Created by dezhonger on 2017/2/13.
 * 二维01背包
 * dp[m][n]表示用m个0和n个1能组成最多的字符串的个数
 * dp[m][n] = Math.max(dp[m][n], 1 + dp[m - s0][n - s1])
 * s0, s1表示当前字符串的0和1的个数
 */
public class Leetcode474 {

	public int[] cnt(String s) {
		int[] ans = new int[2];
		for(int i = 0; i < s.length(); i++) {
			ans[s.charAt(i) - '0']++;
		}
		return ans;
	}

	public int findMaxForm(String[] strs, int m, int n) {
		int[][] dp = new int[m + 1][n + 1];
		for(int i = 0; i < strs.length; i++) {
			int[] count = cnt(strs[i]);
			int c0 = count[0];
			int c1 = count[1];
			//注意枚举顺序
			for(int k = m; k >= c0; k--) {
				for(int j = n; j >= c1; j--) {
					dp[k][j] = Math.max(dp[k][j], dp[k - c0][j - c1] + 1);
				}
			}
		}
//		System.out.println(dp[m][n]);
		return dp[m][n];
	}

	public static void main(String[] args) {
		new Leetcode474().findMaxForm(new String[]{"10", "0", "1"}, 1, 1);
		new Leetcode474().findMaxForm(new String[]{"10", "0001", "111001", "1", "0"}, 5, 3);
	}
}
