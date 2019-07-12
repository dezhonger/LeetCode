package com.dezhonger.y2019.m07.d12;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0886 {
    //12 13 24
    int[] r;
    int[][] d;
    int n;
    boolean f;

    public static void main(String[] args) {
        System.out.println(new Leetcode0886().possibleBipartition(4, new int[][]{{1,2},{1,3},{2,4}}));
    }
    public boolean possibleBipartition(int N, int[][] dislikes) {
        d = new int[N + 1][N + 1];
        r = new int[N + 1];
        n = N;
        f = true;
        for (int[] i : dislikes) {
            int x = i[0];
            int y = i[1];
            d[x][y] = d[y][x] = 1;
        }

        for (int i = 1; i <= N; i++) {
            if (r[i] == 0) {
                dfs(i, 1);
            }
            if (!f) return false;
        }
        return true;

    }

    private void dfs(int node, int x) {
        if (r[node] == 0) r[node] = x;
        for (int i = 1; i <= n; i++) {
            if (d[node][i] == 1) {
                if (r[i] == 0) {
                    dfs(i, 3 - x);
                } else {
                    if (r[i] == x) {
                        f = false;
                        break;
                    }
                }
            }
        }
    }
}
