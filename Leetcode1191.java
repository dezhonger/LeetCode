
import java.util.Arrays;

/**
 * Created by zhangweilong on 2019/09/17
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/09/17
 */
public class A {
    public static void main(String[] args) {
        System.out.println(new A().kConcatenationMaxSum(new int[]{1, 2}, 3));
        System.out.println(new A().kConcatenationMaxSum(new int[]{1, -2, 1}, 5));
        System.out.println(new A().kConcatenationMaxSum(new int[]{-1, -2}, 7));
    }

    long f(int[] arr) {
        long r = 0;
        long cur = 0;
        for (int i = 0; i < arr.length; i++) {
            cur += arr[i];
            r = Math.max(r, cur);
        }
        return r;
    }

    long g(int[] arr) {
        long r = 0;
        long cur = 0;
        for (int i = arr.length - 1; i >= 0; i--) {
            cur += arr[i];
            r = Math.max(r, cur);
        }
        return r;
    }

    long h(int[] arr) {
        long[] dp = new long[arr.length];
        dp[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            dp[i] = Math.max(arr[i], dp[i - 1] + arr[i]);
        }
        return Math.max(0, Arrays.stream(dp).max().getAsLong());
    }

    public int kConcatenationMaxSum(int[] arr, int k) {

        int sum = Arrays.stream(arr).sum();
        int mod = 10_0000_0007;
        long res = h(arr);
        if (k == 1) return (int) (res % mod);
        if (k == 2) {
            long cur = (f(arr) + g(arr));
            cur = Math.max(cur, res);
            return (int) (cur % mod);
        } else {
            if (sum > 0) {
                long cur = 1L * (k - 2) * sum + f(arr) + g(arr);
                cur = Math.max(cur, res);
                return (int) (cur % mod);
            } else {
                long c = f(arr) + g(arr);
                c = Math.max(c, res);
                return (int) (c % mod);
            }
        }

    }
}
