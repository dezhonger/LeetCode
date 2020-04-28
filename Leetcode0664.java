package com.netease.music.leetcode.hard;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/04/28
 */
public class Leetcode0664 {

    public static void main(String[] args) {
        System.out.println(new Leetcode0664().strangePrinter("aaabbb"));
        System.out.println(new Leetcode0664().strangePrinter("aba"));
    }


    int[][] dp;
    char[] c;

    public int strangePrinter(String s) {
        int len = s.length();
        dp = new int[len][len];
        for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], -1);
        c = s.toCharArray();
        return dfs(0, len - 1, c);
    }

    private int dfs(int l, int r, char[] c) {
        if (l > r) return 0;
        if (l == r) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        int mi = Integer.MAX_VALUE;
        if (c[l] == c[r]) {
            char ch = c[l];
            while (l + 1 < r && c[l + 1] == ch) l++;
            while (r - 1 > l && c[r - 1] == ch) r--;
            mi = Math.min(mi, 1 + dfs(l + 1, r - 1, c));
        }
        for (int k = l; k < r; k++) {
            if (c[k] == c[r]) mi = Math.min(mi, dfs(l, k, c) + dfs(k + 1, r, c) - 1);
            else mi = Math.min(mi, dfs(l, k, c) + dfs(k + 1, r, c));
        }
        dp[l][r] = mi;
        return dp[l][r];
    }
}
