package com.y2020.m04.d12;

/**
 * Created by zhangweilong on 2020/04/12
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/04/12
 */
public class Leetcode1411 {
    int[] f(int x) {
        int[] state = new int[3];
        state[0] = x % 3;
        state[1] = x / 3 % 3;
        state[2] = x / 9;
        return state;
    }

    boolean check(int[] s1) {
        return s1[0] != s1[1] && s1[1] != s1[2];
    }

    boolean check(int a, int b) {
        int[] s1 = f(a);
        int[] s2 = f(b);
        return check(s1) && check(s2) && s1[0] != s2[0] && s1[1] != s2[1] && s1[2] != s2[2];
    }

    public int numOfWays(int n) {
        int mod = 10_0000_0007;
        long[][] d = new long[n + 1][30];
        int ma = 24;
        for (int last = 0; last < ma; last++) {
            if (check(f(last))) d[1][last] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < ma; j++) {
                for (int k = 0; k < ma; k++) {
                    if (check(k, j)) d[i][j] += d[i - 1][k];
                    d[i][j] %= mod;
                }
            }
        }
        long ans = 0;
        for (int last = 0; last < ma; last++) ans += d[n][last];
        return (int) (ans % mod);
    }
}
