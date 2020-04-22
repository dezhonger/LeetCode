import java.util.Arrays;

public class Leetcode0600 {
    int[] a;
    int len;
    int[][] dp = new int[40][2];

    int[] f(int num) {
        char[] c = Integer.toBinaryString(num).toCharArray();
        len = c.length;
        int[] a = new int[len];
        for (int i = 0; i < len; i++) a[i] = c[len - 1 - i] - '0';
        return a;
    }

    int solve(int index, int last, boolean limit) {
        if (index == -1) return 1;
        if (!limit && dp[index][last] != -1) return dp[index][last];
        int h = limit ? a[index] : 1;
        int res = 0;
        for (int i = 0; i <= h; i++) {
            boolean nextLimit = limit && i == h;
            if (i == 0) res += solve(index - 1, i, nextLimit);
            else if (i == 1) {
                if (last != 1) res += solve(index - 1, i, nextLimit);
            }
        }
        if (!limit) dp[index][last] = res;
        return res;
    }

    public int findIntegers(int num) {
        a = f(num);
        for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], -1);
        return solve(len - 1, -1, true);
    }
}
