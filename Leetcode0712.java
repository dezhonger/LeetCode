
import java.util.Arrays;

/**
 * Created by dezhonger on 2019/7/17
 */
public class Leetcode0712 {


    public int minimumDeleteSum(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
        dp[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
            char c1 = s1.charAt(i - 1);
            dp[i][0] = dp[i - 1][0] + c1;
        }
        for (int j = 1; j <= len2; j++) {
            char c2 = s2.charAt(j - 1);
            dp[0][j] = dp[0][j - 1] + c2;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                char c1 = s1.charAt(i - 1);
                char c2 = s2.charAt(j - 1);
                if (c1 == c2) {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i][j]);
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j] + c1, dp[i][j - 1] + c2);
                }
            }
        }
        return dp[len1][len2];
    }
}
