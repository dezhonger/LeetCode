package com.dezhonger.y2020.m02.d15;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

/**
 * Created by dezhonger on 2020/02/15
 *
 * @author dezhonger
 * @since 2020/02/15
 */
public class Leetcode0909 {
    public static void main(String[] args) {
        int[][] x = new int[][]
//                {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
                {
                        {-1, -1, 27, 13, -1, 25, -1},
                        {-1, -1, -1, -1, -1, -1, -1},
                        {44, -1, 8, -1, -1, 2, -1},
                        {-1, 30, -1, -1, -1, -1, -1},
                        {3, -1, 20, -1, 46, 6, -1},
                        {-1, -1, -1, -1, -1, -1, 29},
                        {-1, 29, 21, 33, -1, -1, -1}};

        System.out.println(new Leetcode0909().snakesAndLadders(x));

    }

    public int snakesAndLadders(int[][] board) {
        int n = board.length;


        Map<Integer, Integer> mp = new HashMap<>();
        boolean d = true;
        int c = 1;
        for (int i = n - 1; i >= 0; i--, d = !d) {
            if (d) for (int j = 0; j < n; j++, c++) {
                if (board[i][j] > 0) mp.put(c, board[i][j]);
            }
            else for (int j = n - 1; j >= 0; j--, c++) {
                if (board[i][j] > 0) mp.put(c, board[i][j]);
            }
        }

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{1, 0});
        boolean[] v = new boolean[404];
        v[1] = true;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int val = p[0];
            int step = p[1];
            if (val == n * n) return step;
            for (int k = val + 1; k <= Math.min(n * n, val + 6); k++) {
                int nxt = mp.get(k) == null ? k : mp.get(k);
                if (!v[nxt]) {
                    q.add(new int[]{nxt, step + 1});
                    v[nxt] = true;
                }
            }
        }
        return -1;
    }

}
