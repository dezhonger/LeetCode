package com.dezhonger.y2020.m01.d09;

/**
 * Created by dezhonger on 2020/01/08
 *
 * @author dezhonger
 * @since 2020/01/08
 */
public class Leetcode0688 {


    public double knightProbability(int N, int K, int r, int c) {
        int[] dx = new int[]{-2, -1, 1, 2, 2, 1, -1, -2};
        int[] dy = new int[]{1, 2, 2, 1, -1, -2, -2, -1};
        double[][][] dp = new double[2][N][N];
        dp[0][r][c] = 1.0;
        int cur = 1;
        for (int i = 0; i < K; i++) {
            clean(dp[cur], N);

            for (int j = 0; j < 8; j++) {
                for (int a = 0; a < N; a++) {
                    for (int b = 0; b < N; b++) {
                        int x = a + dx[j];
                        int y = b + dy[j];
                        if (x >= 0 && y >= 0 && x < N && y < N) {
                            dp[cur][a][b] += 1.0 / 8 * dp[1 - cur][x][y];
                        }
                    }
                }
            }
            cur = 1 - cur;
        }
        double res = 0;
        for (int a = 0; a < N; a++) for (int b = 0; b < N; b++) res += dp[K % 2][a][b];
        return res;
    }

    private void clean(double[][] doubles, int N) {
        for (int a = 0; a < N; a++) for (int b = 0; b < N; b++) doubles[a][b] = 0;
    }
}
