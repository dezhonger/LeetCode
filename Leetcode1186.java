
import java.util.Arrays;

/**
 * Created by dezhonger on 2019/9/12
 */
public class Leetcode1186 {
    public int maximumSum(int[] arr) {
        int len = arr.length;
        int[] l = new int[len];
        int[] r = new int[len];
        l[0] = arr[0];
        r[len - 1] = arr[len - 1];
        int res = Integer.MIN_VALUE;
        for (int i = 1; i < len; i++) {
            l[i] = Math.max(arr[i], arr[i] + l[i - 1]);
        }
        for (int i = len - 2; i >= 0; i--) {
            r[i] = Math.max(arr[i], arr[i] + r[i + 1]);
        }
        res = Math.max(res, Arrays.stream(l).max().getAsInt());
        res = Math.max(res, Arrays.stream(r).max().getAsInt());
        for (int i = 0; i < len; i++) {
            if (i > 0) res = Math.max(res, l[i - 1]);
            if (i < len - 1) res = Math.max(res, r[i + 1]);
            if (i > 0 && i < len - 1) res = Math.max(res, l[i - 1] + r[i + 1]);
        }
        return res;
    }
}
