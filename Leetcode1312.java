package com.dezhonger.y2020.m01;

/**
 * Created by dezhonger on 2020/01/05
 *
 * @author dezhonger
 * @since 2020/01/05
 */
public class Leetcode1312 {
    int res = Integer.MAX_VALUE;

    public static void main(String[] args) {
        System.out.println(new Leetcode1312().minInsertions("dyyuyabzkqaybcspq"));
    }

    public int minInsertions(String s) {
        for (int i = 0; i < s.length(); i++) {
            find(s.substring(0, i), s.substring(i));
            find(s.substring(0, i), s.substring(i + 1));
        }
        return res;
    }

    private void find(String a, String b) {
        if (a.length() == 0 && b.length() == 0) {
            res = 0;
            return;
        }
        if (a.length() == 0) {
            res = Math.min(res, b.length());
            return;
        }
        if (b.length() == 0) {
            res = Math.min(res, a.length());
            return;
        }
        int[][] dp = new int[a.length() + 1][b.length() + 1];
        for (int i = 0; i < a.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (a.charAt(i) == b.charAt(b.length() - j - 1)) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = Math.max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int h = a.length() + b.length() - 2 * dp[a.length()][b.length()];
        res = Math.min(res, h);
    }

}
