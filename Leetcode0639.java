package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/4/13
 */
public class Leetcode0639 {
    public static void main(String[] args) {
//        System.out.println(new Leetcode0639().numDecodings("*"));
//        System.out.println(new Leetcode0639().numDecodings("1*"));
//        System.out.println(new Leetcode0639().numDecodings("**"));
//        System.out.println(new Leetcode0639().numDecodings("*1*"));
//        System.out.println(new Leetcode0639().numDecodings("*1*1*0"));
//        System.out.println(new Leetcode0639().numDecodings("126"));
//        System.out.println(new Leetcode0639().numDecodings("1*72*"));
//        System.out.println(new Leetcode0639().numDecodings("**********1111111111"));
    }

    int f(char c) {
        if (c == '1') return 9;
        else if (c == '2') return 6;
        return 0;
    }

    int g(char c) {
        if (c <= '6') return 2;
        return 1;
    }

    int h(char d, char c) {
        int dd = d - '0';
        int cc = c - '0';
        int e = dd * 10 + cc;
        if (e >= 10 && e <= 26) return 1;
        return 0;

    }

    public int numDecodings(String s) {
        int len = s.length();
        int mod = 10_0000_0007;
        //dp[i][0] 第i位单独处理 dp[i][1]第i位和第i-1位一起处理
        long[][] dp = new long[len + 1][3];
        char ch = s.charAt(0);
        if (ch == '0') return 0;
        dp[0][0] = 1;
        if (ch == '*') {
            dp[1][0] = 9;
        } else {
            dp[1][0] = 1;
        }
        for (int i = 2; i <= len; i++) {
            char c = s.charAt(i - 1);
            char d = s.charAt(i - 2);
            long l1 = dp[i - 1][0] + dp[i - 1][1];
            long l2 = dp[i - 2][0] + dp[i - 2][1];
            if (c == '*') {
                dp[i][0] = l1 * 9L;
                if (d == '*') dp[i][1] = 15L * l2;
                else dp[i][1] = 1L * f(d) * l2;
            } else if (c == '0') {
                if (d == '*') dp[i][1] = 2L * l2;
                else if (d == '1' || d == '2') dp[i][1] = l2;
                else return 0;
            } else {
                dp[i][0] = l1;
                if (d == '*') dp[i][1] = 1L * g(c) * l2;
                else dp[i][1] = 1L * h(d, c) * l2;
            }
            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
        return (int) (dp[len][0] + dp[len][1]) % mod;
    }


}
