package com.dezhonger.y2019.m12.d26;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by dezhonger on 2019/12/26
 *
 * @author dezhonger
 * @since 2019/12/26
 */
public class Leetcode0934 {

    Queue<Node> q = new ArrayDeque<>();
    int m, n;
    int[] dx = new int[]{0, 0, -1, 1};
    int[] dy = new int[]{-1, 1, 0, 0};
    boolean[] v;



    public int shortestBridge(int[][] A) {
        // 1 is island
        this.m = A.length;
        this.n = A[0].length;
        v = new boolean[m * n];
        boolean f = false;
        for (int i = 0; !f && i < m; i++) {
            for (int j = 0; !f && j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j);
                    f = true;
                }
            }
        }

        while (!q.isEmpty()) {
            Node poll = q.poll();
            int x = poll.x;
            int y = poll.y;
            int s = poll.s;
            for (int i = 0; i < 4; i++) {
                int _x = x + dx[i];
                int _y = y + dy[i];
                if (_x >= 0 && _y >= 0 && _x < m && _y < n && !v[_x * n + _y]) {
                    if (A[_x][_y] == 1) {
                        return s;
                    } else {
                        v[_x * n + _y] = true;
                        Node n = new Node(_x, _y, s + 1);
                        q.add(n);
                    }
                }
            }
        }
        //cannot arrive here
        return -1;
    }


    private void dfs(int[][] a, int x, int y) {
        v[x * n + y] = true;
        a[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int _x = x + dx[i];
            int _y = y + dy[i];
            if (_x >= 0 && _y >= 0 && _x < m && _y < n && a[_x][_y] == 1) {
                dfs(a, _x, _y);
            }
        }
        q.add(new Node(x, y, 0));
    }

    class Node {
        int x, y, s;

        public Node(int x, int y, int s) {
            this.x = x;
            this.y = y;
            this.s = s;
        }
    }
}
