package com.netease.music.p20200212;

/**
 * Created by dezhonger on 2020/2/12
 */
public class Leetcode0960 {
    public int minDeletionSize(String[] A) {
        int len = A.length;
        int col = A[0].length();
        boolean[][] compare = new boolean[col][col];
        for (int i = 0; i < col; i++) {
            for (int j = i + 1; j < col; j++) {
                boolean f = true;
                for (int k = 0; k < len; k++) {
                    if (A[k].charAt(j) < A[k].charAt(i)) {
                        f = false;
                        break;
                    }
                }
                compare[i][j] = f;
            }
        }

        int[] dp = new int[col];
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < col; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if(compare[j][i]) dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            res = Math.max(res, dp[i]);
        }
        return col - res;
    }
}
