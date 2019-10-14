package com.netease.music.pe;

/**
 * Created by dezhonger on 2019/10/14
 */
public class PE148 {
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        long r = 0;
        for (int i = 0; i < 10_0000_0000; i++) {
            r += count(i);
        }
        System.out.println(r);
        long end = System.currentTimeMillis();
        System.out.println((end - start) + "ms");

    }

    static long count(long n) {
        long result = 1;
        while (n > 0) {
            result *= (n % 7) + 1;
            n /= 7;
        }
        return result;
    }

}
