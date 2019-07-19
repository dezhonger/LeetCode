
import java.util.Arrays;

/**
 * Created by dezhonger on 2019/07/19
 *
 * @author dezhonger
 * @since 2019/07/19
 */
public class Leetcode0902 {
    int[] d;
    int res = 0;
    int[] bit;


    int dp[];

    int dfs(int pos, boolean limit)
    {
        if(pos == 0) return 1;
        if(!limit && dp[pos] != -1) return dp[pos];
        int last = limit ? bit[pos] : 9;
        int result = 0;
        for(int i = 0; i < d.length; i++) {
            if (d[i] > last) continue;
            result += dfs(pos - 1, limit && d[i] == last);
        }
        if(!limit) dp[pos] = result;
        return result;
    }



    public int atMostNGivenDigitSet(String[] D, int N) {
        d = new int[D.length];
        dp = new int[15];
        bit = new int[15];
        Arrays.fill(dp, -1);

        for (int i = 0; i < D.length; i++) {
            d[i] = Integer.valueOf(D[i]);
        }
        int tmp = D.length;
        for (int i = 1; i < (N + "").length(); i++) {
            res += tmp;
            tmp = tmp * D.length;
        }

        int len = 0;
        int n = N;
        while (n > 0) {
            bit[++len] = n % 10;
            n /= 10;
        }
        res += dfs(len, true);
        return res;
    }
}
