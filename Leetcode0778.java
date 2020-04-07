package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2020/4/7
 */
public class Leetcode0778 {
    public static void main(String[] args) {
        Leetcode0778 sol = new Leetcode0778();
        int ans = sol.swimInWater(new int[][]{
                {0, 1, 2, 3, 4},
                {24, 23, 22, 21, 5},
                {12, 13, 14, 15, 16},
                {11, 17, 18, 19, 20},
                {10, 9, 8, 7, 6},
        });
        System.out.println(ans);
    }
    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, 1, 0, -1};
    int[] fa;
    int[][] g;

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }

    void init(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fa[i * n + j] = i * n + j;
            }
        }
    }

    boolean can(int v, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] > v) continue;
                for (int k = 0; k < 4;k ++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && y >= 0 && x < n && y < n && g[x][y] <= v)
                        union(i * n + j, x * n + y);
                }
            }
        }
        int f1 = find(0);
        int f2 = find(n * n -1);
        return f1 == f2;
    }

    public int swimInWater(int[][] grid) {
        this.g = grid;
        int n = grid.length;
        fa = new int[n * n];
        int low = 0, high = n * n - 1;
        while (low < high) {
            init(n);
            int mid = (low + high) / 2;
            if (can(mid, n)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
