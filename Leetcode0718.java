package com.y2019.m12.d26;

/**
 * Created by zhangweilong on 2019/12/25
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/25
 */
public class Leetcode0718 {
    public static void main(String[] args) {
        Leetcode0718 sol = new Leetcode0718();
        System.out.println(sol.findLength(new int[]{0, 1, 1, 1, 1}, new int[]{1, 0, 1, 0, 1}));
    }
    public int findLength(int[] A, int[] B) {
        int[][] dp = new int[A.length + 1][B.length + 1];
        int res = 0;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                if (A[i] == B[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = 0;
                }
                res = Math.max(res, dp[i + 1][j + 1]);
            }
        }
        return res;
    }

}
