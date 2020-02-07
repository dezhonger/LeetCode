package com.dezhonger.y2020.m02.d07;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2020/02/07
 *
 * @author dezhonger
 * @since 2020/02/07
 */
public class Leetcode0866 {
    int[] d = new int[]{1, 10, 100, 1000, 10000};
    int N;
    int maxN = 2_0000_0000;

    public static void main(String[] args) {
        System.out.println(new Leetcode0866().primePalindrome(930));
    }

    int getLen(int x) {
        int r = 0;
        while (x > 0) {
            x /= 10;
            r++;
        }
        return r;
    }


    int reverse(String s, String s2) {
        return Integer.valueOf(new StringBuilder(s).reverse().append(s2).append(s).toString());
    }

    String f(String s, int len) {
        int l = s.length();
        if (l < len) {
            for (int i = 0; i < len - l; i++) s = "0" + s;
        }
        return s;
    }

    List<Integer> getPalindrome(int n) {
        List<Integer> list = new ArrayList<>();
        if (n % 2 == 0) {
            int m = n / 2;
            for (int i = 1; i < d[m]; i += 2) {
                String str = i + "";
                int tmp = reverse(f(str, m), "");
                if (tmp >= N && tmp < maxN) list.add(tmp);
            }
        } else {
            int m = n / 2;
            if (m == 0) {
                for (int tmp = 2; tmp <= 10; tmp++) if (tmp >= N && tmp < maxN) list.add(tmp);
            } else {
                for (int j = 0; j < 10; j++) {
                    for (int i = 1; i < d[m]; i += 2) {
                        String str = i + "";
                        int tmp = reverse(f(str, m), j + "");
                        if (tmp >= N && tmp < maxN) list.add(tmp);
                    }

                }
            }
        }
        return list;
    }

    boolean isPrime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    public int primePalindrome(int N) {
        this.N = N;
        int len = getLen(N);
        for (int i = len; i < 10; i++) {
            List<Integer> palindrome = getPalindrome(i);
            Collections.sort(palindrome);
            for (int x : palindrome) {
                if (isPrime(x)) return x;
            }
        }

        //cannot reach here
        return -1;
    }
}
