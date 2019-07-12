package com.dezhonger.y2019.m07.d12;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0840 {
    public static void main(String[] args) {
        int[][] p = new int[][]{
                {4, 3, 8, 4},
                {9, 5, 1, 9},
                {2, 7, 6, 2}
        };
        int x = new Leetcode0840().numMagicSquaresInside(p);
        System.out.println(x);
    }

    public int numMagicSquaresInside(int[][] grid) {
        int r = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                boolean f = check(grid, i, j);
                if (f) r++;
            }
        }
        return r;
    }

    private boolean check(int[][] grid, int r, int c) {
        int bit = 0;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (grid[i][j] <= 0 && grid[i][j] >= 10) return false;
                bit |= (1 << (grid[i][j] - 1));
            }
        }
        if (bit != ((1 << 9) - 1)) return false;


        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        for (int i = r; i < r + 3; i++) {
            int tmp = 0;
            for (int j = c; j < c + 3; j++) tmp += grid[i][j];
            if (tmp != sum) return false;
        }
        for (int j = c; j < c + 3; j++) {
            int tmp = 0;
            for (int i = r; i < r + 3; i++) tmp += grid[i][j];
            if (tmp != sum) return false;
        }

        int x = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int y = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
        if (sum != x) return false;
        if (sum != y) return false;


        return true;
    }
}
