
/**
 * Created by zhangweilong on 2019/08/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/01
 */
public class Leetcode0923 {

    public int threeSumMulti(int[] A, int target) {
        int mod = 1000000007;
        int[] f = new int[101];
        for (int v : A) f[v]++;
        long ret = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {
                int k = target - i - j;
                if (i <= k && k <= 100) {
                    if (i < j && j < k) {
                        ret += (long) f[i] * f[j] * f[k];
                    } else if (i < j && j == k) {
                        ret += (long) f[i] * f[j] * (f[j] - 1) / 2;
                    } else if (i == j && j < k) {
                        ret += (long) f[k] * f[j] * (f[j] - 1) / 2;
                    } else if (i == j && j == k) {
                        ret += (long) f[i] * (f[i] - 1) * (f[i] - 2) / 6;
                    }
                }
            }
        }
        return (int) (ret % mod);
    }
}
