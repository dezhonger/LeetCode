
/**
 * Created by zhangweilong on 2019/08/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/01
 */
public class Leetcode0920 {

    public int numMusicPlaylists(int N, int L, int K) {
        //前i个人唱j首歌的方法数
        long[][] dp = new long[L + 1][N + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= N; j++) {
                //dp[i][j] = dp[i-1][j-1] * (L - j + 1) + dp[i - 1][j] * Math.max(0, j - K)
                dp[i][j] = dp[i - 1][j - 1] * (N - j + 1);
                dp[i][j] += dp[i - 1][j] * Math.max(0, j - K);
                dp[i][j] %= 10_0000_0007L;
            }
        }
        return (int) dp[L][N];
    }
}
