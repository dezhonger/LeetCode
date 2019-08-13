
/**
 * Created by zhangweilong on 2019/08/13
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/13
 */
public class Leetcode1115 {

    public int numRollsToTarget(int d, int f, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= d; i++) {
            int[] tmp = new int[target + 1];
            for (int j = target; j >= 0; j--) {
                for (int k = 1; k <= f; k++) {
                    if (j - k >= 0) tmp[j] += dp[j - k];
                    tmp[j] %= 10_0000_0007;
                }
            }
            System.arraycopy(tmp, 0, dp, 0, tmp.length);
        }
        return dp[target];
    }
}
