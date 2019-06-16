package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/6/17
 */
public class Leetcode1092 {


    int[][] flag;
    int len1;
    int len2;
    char[] c1;
    char[] c2;
    int[][] dp;
    StringBuilder sb = new StringBuilder();


    private int cal(int[][] dp, int i, int j) {
        if (i >= 0 && j >= 0) return dp[i][j];
        else return 0;
    }

    private void print(int i, int j) {
        if (i < 0 || j < 0) {
            for (int k = 0; k <= i; k++) sb.append(c1[k]);
            for (int k = 0; k <= j; k++) sb.append(c2[k]);
            return;
        }
        if (flag[i][j] == 0) {
            print(i - 1, j - 1);
            sb.append(c1[i]);
        } else if (flag[i][j] == 1) {
            print(i - 1, j);
            sb.append(c1[i]);
        } else {
            print(i, j - 1);
            sb.append(c2[j]);
        }
    }

    public String shortestCommonSupersequence(String str1, String str2) {

        len1 = str1.length();
        len2 = str2.length();
        c1 = str1.toCharArray();
        c2 = str2.toCharArray();
        dp = new int[len1][len2];
        flag = new int[len1][len2];


        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (c1[i] == c2[j]) {
                    dp[i][j] = cal(dp, i - 1, j - 1) + 1;
                    flag[i][j] = 0;
                } else {
                    if (cal(dp, i - 1, j) >= cal(dp, i, j - 1)) {
                        dp[i][j] = cal(dp, i - 1, j);
                        flag[i][j] = 1;
                    } else {
                        dp[i][j] = cal(dp, i, j - 1);
                        flag[i][j] = -1;
                    }
                }
            }
        }
        print(len1 - 1, len2 - 1);
        return sb.toString();
    }
}
