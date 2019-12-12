package com.dezhonger.le;

/**
 * Created by dezhonger on 2019/12/12
 *
 * @author dezhonger
 * @since 2019/12/12
 */
public class Leetcode0877 {


    int[][] d;
    int[][] v;

    public boolean stoneGame(int[] piles) {
        d = new int[piles.length][piles.length];
        v = new int[piles.length][piles.length];
        return f( 0, piles.length - 1, piles) > 0;
    }


    //l, r区间内，先手比后手可以多拿到的石子数
    int f(int l, int r, int[] piles) {
        if (v[l][r] == 1) return d[l][r];
        if (l == r) return piles[l];
        int a = piles[l] - f(l + 1, r, piles);
        int b = piles[r] - f(l, r - 1, piles);
        d[l][r] = Math.max(a, b);
        v[l][r] = 1;
        return d[l][r];
    }
}
