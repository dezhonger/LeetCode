package p1107.p20170210;

/**
 * Created by dezhonger on 2017/2/10.
 */
public class Leetcode516 {
	int[][] dp;

	public int dfs(int a, int b, String s) {
		if(dp[a][b] != -1) return dp[a][b];
		if(s.charAt(a) == s.charAt(b)) {
			return dp[a][b] = dfs(a + 1, b - 1, s) + 2;
		}
		int ans1 = dfs(a + 1, b, s);
		int ans2 = dfs(a, b - 1, s);
		return dp[a][b] = Math.max(ans1, ans2);

	}
	public int longestPalindromeSubseq(String s) {
		if(s == null || s.length() == 0) return 0;
		int len = s.length();
		dp = new int[len][len];
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < len; j++) {
				if(i == j) dp[i][j] = 1;
				else if(i < j) dp[i][j] = -1;
				else dp[i][j] = 0;
			}
		}
		for(int i = 0; i < len; i++) dp[i][i] = 1;
		dfs(0, len - 1, s);
		return dp[0][len-1];
	}

	public static void main(String[] args) {
		System.out.println(new Leetcode516().longestPalindromeSubseq("cbbd"));
	}
}
