package com.dezhonger.y2020.m02.d07;

/**
 * Created by dezhonger on 2020/02/07
 *
 * @author dezhonger
 * @since 2020/02/07
 */
public class Leetcode0866_2 {
    boolean isPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    public int primePalindrome(int N) {
        //所有偶数回文数都是11的倍数，也就是说不是prime，11是个例外
        if (8 <= N && N <= 11) return 11;
        for (int i = 1; i < 100000; i++) {
            String s = i + "";
            String sr = new StringBuilder(s).reverse().toString();
            int x = Integer.valueOf(s + sr.substring(1));
            if (x >= N && isPrime(x)) return x;
        }
        return -1;
    }
}
