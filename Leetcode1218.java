
/**
 * Created by dezhonger on 2019/11/27
 *
 * @author dezhonger
 * @since 2019/11/27
 */
public class Leetcode1218 {


    public int longestSubsequence(int[] arr, int difference) {
        int offset = 30000;
        int[] dp = new int[100010];
        //dp[i] 以i结尾的等差数列的长度
        for (int i = 0; i < arr.length; i++) {
            dp[offset + arr[i]] = 1;
            dp[offset + arr[i]] = Math.max(dp[offset + arr[i]], dp[offset + arr[i] - difference] + 1);
        }
        int res = 0;
        for (int i = 0; i < dp.length; i++) {
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
