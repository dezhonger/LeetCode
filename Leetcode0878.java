package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2020/04/26
 */
public class Leetcode0878 {

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long lcm(int a, int b) {
        return 1L * a * b / gcd(a, b);
    }

    long findNum(long N, int A, int B) {
        long a = N / A;
        long b = N / B;
        long c = N / lc;
        return a + b - c;
    }

    long lc;

    public int nthMagicalNumber(int N, int A, int B) {
        long l = 1;
        long r = Math.min(1L * A * N, 1L * B * N);
        lc = lcm(A, B);
        while (l < r) {
            long mid = (l + r) / 2;
            long cnt = findNum(mid, A, B);
            if (cnt < N) l = mid + 1;
            else if (cnt > N) r = mid - 1;
            else r = mid;
        }
        return (int) (l % 10_0000_0007);
    }
}
