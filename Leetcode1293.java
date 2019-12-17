package com.netease.music.leetcode;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by dezhonger on 2019/12/17
 *
 * 0可以走，1是obstacle
 * 从(0, 0)走到(m - 1, n - 1)最少需要多少步
 * 可以最多把k个障碍清除掉
 */
public class Leetcode1293 {


    //dp[i][j][k], 到达(i, j), 消除了k个障碍的最少步数
    public int shortestPath(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dp = new int[m][n][k + 1];
        for (int i = 0; i < dp.length;i ++) {
            for (int j = 0; j < dp[i].length; j++) {
                Arrays.fill(dp[i][j], 1000_0000);
            }
        }

        Queue<Node> queue = new ArrayDeque<>();
        int[] dx = new int[]{0, 0, 1, -1};
        int[] dy = new int[]{1, -1, 0, 0};

        queue.add(new Node(0, 0, 0));
        dp[0][0][0] = 0;

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            for (int i = 0; i < 4; i++) {
                int px = node.x + dx[i];
                int py = node.y + dy[i];
                if (px >= 0 && px < m && py >= 0 && py < n && node.k + grid[px][py] <= k) {
                    if (dp[px][py][node.k + grid[px][py]] == 1000_0000) {
                        dp[px][py][node.k + grid[px][py]] = Math.min(dp[px][py][node.k + grid[px][py]], dp[node.x][node.y][node.k] + 1);
                        queue.add(new Node(px, py, node.k + grid[px][py]));
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= k; i++) {
            if (dp[m - 1][n - 1][i] == 1000_0000) continue;
            ans = Math.min(ans, dp[m - 1][n - 1][i]);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }


    private static class Node {
        public Node(int x, int y, int k) {
            this.x = x;
            this.y = y;
            this.k = k;
        }
        int x, y, k;
    }
}
