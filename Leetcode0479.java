
/**
 * Created by zhangweilong on 2019/07/30
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/07/30
 */
public class Leetcode0479 {

    public int largestPalindrome(int n) {
        if (n == 1) return 9;
        int r = (int) (Math.pow(10, n) - 1);
        int l = (int) Math.pow(10, n - 1);
        for (long x = r; x >= l; x--) {
            String tmp = x + "";
            long res = Long.valueOf(tmp + new StringBuilder(tmp).reverse().toString());
            for (long j = r; j * j >= res; j--) {
                if (res % j == 0) {
                    long k = (res / j);
                    if (k >= l && k <= r) {
                        return (int) (res % 1337);
                    }
                }
            }
        }
        return 0;
    }
}
