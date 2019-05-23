package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/23
 */
public class Leetcode0914 {


    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public boolean hasGroupsSizeX(int[] deck) {
        int[] cnt = new int[10000];
        for (int x : deck) cnt[x]++;
        int g = deck.length;
        for (int x : cnt) {
            if ( x > 0) g = gcd(g, x);
        }
        return g != 1;
    }
}
