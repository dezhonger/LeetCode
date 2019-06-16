package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/6/16
 */
public class Leetcode1088 {
    public static void main(String[] args) {
        new Leetcode1088().confusingNumberII(10_0000_0000);
    }

    int res = 0;
    int[] a = new int[]{0, 1, 6, 8, 9};
    int N;

    boolean check(int x) {
        int[] b = new int[]{0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
        int t = 0;
        int cur = x;
        while (x > 0) {
            t = t * 10 + b[x % 10];
            x /= 10;

        }
        return !(cur == t);
    }

    void dfs(int pos, int x) {
        if (x > 0 && check(x)) {
            res++;
        }
        int start = (pos == 0 && x == 0) ? 1 : 0;
        for (int i = start; i < 5; i++) {
            if (1L * x * 10 + a[i] <= N) {
                dfs(pos + 1, x * 10 + a[i]);
            }
        }
    }


    public int confusingNumberII(int N) {
        this.N = N;
        dfs(0, 0);
        return res;
    }
}
