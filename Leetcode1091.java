package com.netease.music.leetcode;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by dezhonger on 2019/6/17
 */
public class Leetcode1091 {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int N = grid.length;
        if (grid[0][0] == 1 || grid[N - 1][N - 1] == 1) return -1;
        int[] dx = new int[]{-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dy = new int[]{-1, 0, 1, -1, 1, -1, 0, 1};
        boolean[] v = new boolean[10010];
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(new Node(0, 0, 1));
        v[0] = true;
        while (!queue.isEmpty()) {
            Node tmp = queue.poll();
            if (tmp.x == N - 1 && tmp.y == N - 1) return tmp.d;
            for (int i = 0; i < 8; i++) {
                int ddx = tmp.x + dx[i];
                int ddy = tmp.y + dy[i];
                if (ddx >= 0 && ddx < N && ddy >= 0 && ddy < N && !v[ddx * N + ddy] && grid[ddx][ddy] == 0) {
                    queue.add(new Node(ddx, ddy, tmp.d + 1));
                    v[ddx * N + ddy] = true;
                }
            }
        }
        return -1;
    }


    class Node {
        Node(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }

        int x, y, d;
    }
}
