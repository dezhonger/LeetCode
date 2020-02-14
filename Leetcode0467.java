package com.netease.music.p20200214;

/**
 * Created by dezhonger on 2020/2/14
 */
public class Leetcode0467 {
    public int findSubstringInWraproundString(String p) {
        //dp[i]以字母i结尾的最大长度
        int[] dp = new int[26];
        int[] f = new int[p.length()];

        for (int i = 0; i < p.length(); i++) {
            f[i] = 1;
            int x = p.charAt(i) - 'a';
            if (i > 0) {
                int last = p.charAt(i - 1) - 'a';
                if ((last + 1) % 26 == x) f[i] = f[i - 1] + 1;
            }
            dp[x] = Math.max(dp[x], f[i]);
        }
        int res = 0;
        for (int x : dp) res += x;
        return res;
    }
}
