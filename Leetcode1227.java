package com.netease.music.p20200205;

/**
 * Created by dezhonger on 2020/2/5
 */
public class Leetcode1227 {
    public double nthPersonGetsNthSeat(int n) {
        double[] d = new double[n + 1];
        d[1] = 1.0;
        double[] s = new double[n + 1];
        s[1] = 1.0;
        for (int i = 2; i <= n; i++) {
            d[i] = s[i - 1];
            d[i] /= i;
            s[i] = s[i - 1] + d[i];
        }
        return d[n];

        //这个也是对的
//        return 1 == n ? 1 : 0.5;
    }
}
