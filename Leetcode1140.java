/**
 * Created by zhangweilong on 2019/07/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/07/29
 */
public class Leetcode1140 {
    public int stoneGameII(int[] piles) {
        int len = piles.length;
        int[][] dp = new int[len + 1][len + 1];
        int[] sum = new int[len];
        sum[len - 1] = piles[len - 1];
        for (int i = len - 2; i >= 0; i--) sum[i] = sum[i + 1] + piles[i];
        for (int i = 0; i < len; i++) dp[i][len] = sum[i];
        for (int i = len - 1; i >= 0; i--) {
            for (int j = len; j >= 1; j--) {
                //j means M,  1 <= x <= 2*M
                //dp[i][j] = Math.max(dp[i][j], dp[i+k][max(j, k)]), 1 <= k <= 2 * j
                for (int k = 1; k <= 2 * j; k++) {
                    int e = Math.min(i + k, len);
                    int f = Math.min(Math.max(k, j), len);
                    dp[i][j] = Math.max(dp[i][j], sum[i] - dp[e][f]);
                }
            }
        }
        return dp[0][1];
    }
}
