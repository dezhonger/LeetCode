package com.dezhonger.y2020.m01.d06;

/**
 * Created by dezhonger on 2020/01/06
 *
 * @author dezhonger
 * @since 2020/01/06
 */
public class Leetcode0684 {
    int[] f;

    public int[] findRedundantConnection(int[][] edges) {
        f = new int[1001];
        for (int i = 0; i < f.length; i++) f[i] = i;
        for (int[] x : edges) {
            int a = x[0];
            int b = x[1];
            int fa = find(a);
            int fb = find(b);
            if (fa == fb) return new int[]{a, b};
            else merge(a, b);
        }
        //cannot reach here
        return new int[2];
    }

    int find(int a) {
        if (f[a] == a) return a;
        else return f[a] = find(f[a]);
    }

    void merge(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) f[fa] = fb;
    }
}
