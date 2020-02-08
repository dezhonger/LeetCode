package com.netease.music.p20200208;

/**
 * Created by dezhonger on 2020/2/8
 */
public class Leetcode0808 {
    double[][] memory;
    public double soupServings(int N) {
        N = (N + 24) / 25;
        if (N >= 500) return 1.0;
        memory = new double[500][500];
        return f(N, N);
    }


    double f(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0;
        if (memory[a][b] > 0) return memory[a][b];
        double res = 0;
        res += f(a - 4, b);
        res += f(a - 3, b - 1);
        res += f(a - 2, b - 2);
        res += f(a - 1, b - 3);
        res *= 0.25;
        memory[a][b] = res;
        return res;
    }
}
