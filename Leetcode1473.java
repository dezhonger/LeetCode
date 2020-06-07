package com.netease.music.leetcode.contest.no192;


/**
 * Created by dezhonger on 2020/06/08
 */
public class Leetcode1473 {
    public static void main(String[] args) {
        // 1 2 2 1 1
        System.out.println(new Leetcode1473().minCost(
                new int[]{0, 0, 0, 0, 0},
                new int[][]{
                        {1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1},
                },
                5, 2, 3
        ));

        //2 2 1 2 2
        System.out.println(new Leetcode1473().minCost(
                new int[]{0, 2, 1, 2, 0},
                new int[][]{
                        {1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1},
                },
                5, 2, 3
        ));

        System.out.println(new Leetcode1473().minCost(
                new int[]{3,1, 2, 3},
                new int[][]{
                        {1, 1, 1},{1, 1, 1},{1, 1, 1},{1, 1, 1}
                },
                4, 3, 3
        ));
    }

    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        //第i个房子涂成颜色j有k个街区的最小花费
        int[][][] dp = new int[m][n + 1][target + 1];
        int MAX_V = 1000_0000;
        for (int j = 0; j <= n; j++) for (int k = 0; k <= target; k++) dp[0][j][k] = MAX_V;
        if (houses[0] == 0) {
            for (int i = 1; i <= n; i++) dp[0][i][1] = cost[0][i - 1];
        } else {
            dp[0][houses[0]][1] = 0;
        }

        for (int i = 1; i < m; i++) {
            if (houses[i] == 0) {
                //这个房子随意涂色
                for (int j = 1; j <= n; j++) {
                    dp[i][j][0] = MAX_V;
                    int c = cost[i][j - 1];
                    for (int k = 1; k <= target; k++) {
                        dp[i][j][k] = MAX_V;
                        for (int h = 1; h <= n; h++) {
                            if (h == j) {
                                dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][h][k] + c);
                            } else {
                                dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][h][k - 1] + c);
                            }
                        }
                    }
                }
            } else {
                int j = houses[i], c = 0;
                for (int x = 1; x <= n; x++) {
                    if (x == j) continue;
                    for (int y = 0; y <= target; y++)
                        dp[i][x][y] = MAX_V;
                }

                dp[i][j][0] = MAX_V;
                for (int k = 1; k <= target; k++) {
                    dp[i][j][k] = MAX_V;
                    for (int h = 1; h <= n; h++) {
                        if (h == j) {
                            dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][h][k] + c);
                        } else {
                            dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][h][k - 1] + c);
                        }
                    }
                }
            }

        }
        int ans = MAX_V;
        for (int i = 1; i <= n; i++) {
            ans = Math.min(ans, dp[m - 1][i][target]);
        }
        if (ans == MAX_V) return -1;
        return ans;
    }
}
