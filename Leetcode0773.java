package com.y2020.m03.d29;

import com.y2018.m11.d09.S;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

/**
 * Created by zhangweilong on 2020/03/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/03/29
 */
public class Leetcode0773 {
    public static void main(String[] args) {
        Leetcode0773 sol = new Leetcode0773();
//        System.out.println(sol.slidingPuzzle(new int[][] {
//                {1,2,3},
//                {4,0,5},
//        }));

        System.out.println(sol.slidingPuzzle(new int[][] {
                {1,2,3},
                {5, 4, 0},
        }));
    }

    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, 1, 0, -1};

    int hash(int[][] a) {
        return a[0][0] + a[0][1] * 10 + a[0][2] * 100
                + a[1][0] * 1000 + a[1][1] * 10000 + a[1][2] * 10_0000;

    }

    int[][] rehash(int v) {
        int[] a = new int[6];
        int i = 0;
        while (v > 0) {
            a[i++] = v % 10;
            v /= 10;
        }
        int[][] r = new int[2][3];
        r[0][0] = a[0];
        r[0][1] = a[1];
        r[0][2] = a[2];

        r[1][0] = a[3];
        r[1][1] = a[4];
        r[1][2] = a[5];
        return r;
    }

    int[][] cp(int[][] a) {
        int[][] r = new int[2][3];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                r[i][j] = a[i][j];
            }
        }
        return r;
    }

    void swap(int[][] a, int x1, int y1, int x2, int y2) {
        int tmp = a[x1][y1];
        a[x1][y1] = a[x2][y2];
        a[x2][y2] = tmp;
    }

    public int slidingPuzzle(int[][] board) {
        Queue<State> queue = new ArrayDeque<>();
        int v = hash(board);
        int target = hash(new int[][]{
                {1, 2, 3},
                {4, 5, 0},
        });
        queue.add(new State(v, 0));
        Set<Integer> set = new HashSet<>();
        set.add(v);
        while (!queue.isEmpty()) {
            State poll = queue.poll();
            if (poll.v == target) return poll.s;

            int[][] a =rehash(poll.v);
            int _x = -2, _y = -2;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (a[i][j] == 0) {
                        _x = i;
                        _y = j;
                    }
                }
            }
            for (int k = 0; k < 4; k++) {
                int x = _x + dx[k];
                int y = _y + dy[k];
                if (x >= 0 && y >= 0 && x < 2 && y < 3) {
                    int[][] nxt = cp(rehash(poll.v));
                    swap(nxt, _x, _y, x, y);
                    int nxtv = hash(nxt);
                    if (!set.contains(nxtv)) {
                        set.add(nxtv);
                        queue.add(new State(nxtv, poll.s + 1));
                    }
                }
            }


        }
        return -1;
    }

    class State {
        int v, s;

        public State(int v, int s) {
            this.v = v;
            this.s = s;
        }
    }
}
