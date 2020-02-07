package com.dezhonger.y2020.m02.d07;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2020/02/07
 *
 * @author dezhonger
 * @since 2020/02/07
 */
public class Leetcode0738 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0738().monotoneIncreasingDigits(10));
        System.out.println(new Leetcode0738().monotoneIncreasingDigits(1));
        System.out.println(new Leetcode0738().monotoneIncreasingDigits(0));
        System.out.println(new Leetcode0738().monotoneIncreasingDigits_2(1234));
        System.out.println(new Leetcode0738().monotoneIncreasingDigits_2(332));
    }

    public int monotoneIncreasingDigits_2(int N) {
        List<Integer> list = new ArrayList<>();

        while (N > 0) {
            list.add(N % 10);
            N /= 10;
        }

        int len = list.size();
        int[] a = new int[len];
        for (int i = 0; i < list.size(); i++) {
            a[i] = list.get(len - i - 1);
        }

        int mark = len;
        for (int i = len - 1; i > 0; i--) {
            if (a[i - 1] > a[i]) {
                a[i - 1]--;
                mark = i;
            }
        }
        for (int i = mark; i < len; i++) a[i] = 9;
        int res = 0;
        for (int x : a) {
            res = res * 10 + x;
        }
        return res;
    }

    public int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        List<Integer> list = new ArrayList<>();

        while (N > 0) {
            list.add(N % 10);
            N /= 10;
        }

        int len = list.size();
        int[] a = new int[len];
        for (int i = 0; i < list.size(); i++) {
            a[i] = list.get(len - i - 1);
        }

        for (int i = 0; i < len - 1; i++) {
            if (a[i] > a[i + 1]) {
                a[i]--;
                for (int j = i + 1; j < len; j++) a[j] = 9;
                for (int j = i - 1; j >= 0; j--) {
                    if (a[j] > a[j + 1]) {
                        a[j]--;
                        a[j + 1] = 9;
                    }
                }
                break;
            }
        }

        int res = 0;
        for (int x : a) {
            res = res * 10 + x;
        }
        return res;

    }
}
