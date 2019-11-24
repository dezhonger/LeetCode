

/**
 * Created by dezhonger on 2019/11/24
 */
public class Leetcode1269 {
    //dp[i][j]:第i步在第j格的方法数 dp[0][0] = 1;
    //dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]

    public static void main(String[] args) {
        new Leetcode1269().numWays(3, 2);
    }

    public int numWays(int steps, int arrLen) {
        int mod = 10_0000_0007;
        arrLen = Math.min(steps, arrLen);
        int[] dp = new int[arrLen];
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            int[] t = new int[arrLen];
            for (int j = 0; j < arrLen; j++) {
                if (j > 0) {
                    t[j] += dp[j - 1];
                }
                t[j] += dp[j];
                t[j] %= mod;
                if (j < arrLen - 1) {
                    t[j] += dp[j + 1];
                    t[j] %= mod;
                }
            }
            dp = t;
        }
        return dp[0];
    }
}
