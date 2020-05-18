package com.netease.music.leetcode.hard;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/05/18
 */
public class Leetcode1444 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1444().ways(new String[] {
                "A..", "AAA", "..."
        }, 3));
    }
    final int mod = 10_0000_0007;
    int[][] sum;

    public int ways(String[] pizza, int k) {
        int r = pizza.length;
        int c = pizza[0].length();

        //计算前缀和
        sum = new int[r][c];
        if (pizza[0].charAt(0) == 'A') sum[0][0] = 1;
        for (int i = 1; i < r; i++) sum[i][0] = sum[i - 1][0] + (pizza[i].charAt(0) == 'A' ? 1 : 0);
        for (int i = 1; i < c; i++) sum[0][i] = sum[0][i - 1] + (pizza[0].charAt(i) == 'A' ? 1 : 0);
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (pizza[i].charAt(j) == 'A' ? 1 : 0);
            }
        }
        int[][][] dp = new int[r][c][k + 1];
        dp[0][0][1] = 1;
        for (int x = 2; x <= k; x++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (dp[i][j][x - 1] == 0) continue;
                    for (int z = i + 1; z < r; z++) {
                        if (has(i, j, z - 1, c - 1) && has(z, j, r - 1, c - 1)) {
                            dp[z][j][x] += dp[i][j][x-1];
                            dp[z][j][x] %= mod;
                        }
                    }
                    for (int z = j + 1; z < c; z++) {
                        if (has(i, j, r - 1, z - 1) && has(i, z, r - 1, c - 1)) {
                            dp[i][z][x] += dp[i][j][x-1];
                            dp[i][z][x] %= mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans += dp[i][j][k];
                ans %= mod;
            }
        }
        return ans;

    }

    private boolean has(int a, int b, int c, int d) {
        int s1 = 0;
        int s2 = 0;
        int s3 = 0;
        if (a > 0 && b > 0) s1 = sum[a - 1][b - 1];
        if (a > 0) s2 = sum[a - 1][d];
        if (b > 0) s3 = sum[c][b - 1];
        return sum[c][d] + s1 - s2 - s3 > 0;
    }
}
