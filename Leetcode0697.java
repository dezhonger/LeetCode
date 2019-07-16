
import java.util.Arrays;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0697 {
    public int findShortestSubArray(int[] nums) {
        final int len =50000;
        int[] start = new int[len];
        int[] end = new int[len];
        int[] cnt = new int[len];
        Arrays.fill(start, Integer.MAX_VALUE);
        Arrays.fill(end, Integer.MIN_VALUE);

        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            start[x] = Math.min(start[x], i);
            end[x] = Math.max(end[x], i);
            cnt[x]++;
        }
        int mx = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++) {
            mx = Math.max(mx, cnt[i]);
        }
        int mi = Integer.MAX_VALUE;
        for (int i = 0; i < len ;i++) {
            if (end[i] >= 0 && cnt[i] == mx) {
                mi = Math.min(mi, end[i] - start[i] + 1);
            }
        }
        return mi;
    }
}
