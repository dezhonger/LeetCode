package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/12/22
 */
public class Leetcode0947 {
    public static void main(String[] args) {
        Leetcode0947 sol = new Leetcode0947();
        System.out.println(        sol.removeStones(new int[][]{
                {0, 0},
                {0, 1},
                {1, 0},
                {1, 2},
                {1, 1},
                {2, 2},
        }));
    }

    int[] f;
    int[] num;

    public int removeStones(int[][] stones) {
        f = new int[stones.length];
        num = new int[stones.length];
        for (int i = 0; i < f.length; i++) {
            f[i] = i;
            num[i] = 1;
        }
        for (int i = 0; i < f.length; i++) f[i] = i;
        for (int i = 0; i < stones.length; i++) {
            for (int j = i + 1; j < stones.length; j++) {
                boolean can = check(stones[i], stones[j]);
                if (can) {
                    union(i, j);
                }
            }
        }
        int[] cnt = new int[stones.length];

        for (int i = 0; i < num.length; i++) {
            int parent = find(i);
            cnt[parent] = num[parent];
        }
        int res = 0;
        for (int i = 0; i < num.length; i++){
            if (cnt[i] >= 1) res += cnt[i] - 1;
        }
        return res;
    }

    int find(int x) {
        if (x == f[x]) return x;
        else return f[x] = find(f[x]);
    }

    void union(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) {
            f[fa] = fb;
            num[fb] += num[fa];
        }
    }

    private boolean check(int[] a, int[] b) {
        return a[0] == b[0] || a[1] == b[1];
    }

}
