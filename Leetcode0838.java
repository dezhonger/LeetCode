package com.dezhonger.y2020.m01.d28;

import afu.org.checkerframework.checker.oigj.qual.O;

/**
 * Created by dezhonger on 2020/01/29
 *
 * @author dezhonger
 * @since 2020/01/29
 */
public class Leetcode0838 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0838().pushDominoes(".L.R...LR..L.."));
        System.out.println(new Leetcode0838().pushDominoes("RR.L"));
    }

    public String pushDominoes(String dominoes) {
        String s = "L" + dominoes + "R";
        int len = s.length();

        StringBuilder sb = new StringBuilder();

        for (int i = 0, j = 1; j < len; j++) {
            if (s.charAt(j) == '.') continue;

            char c1 = s.charAt(i);
            char c2 = s.charAt(j);
            if (c1 == c2) {
                for (int k = i; k < j; k++) sb.append(c1);
            } else if (c1 == 'L' && c2 == 'R') {
                sb.append(c1);
                for (int k = i + 1; k < j; k++) sb.append('.');
            } else {
                //c1 == 'R' && c2 == 'L'
                int mid = (i + j) / 2;
                if (mid - i == j - mid) {
                    //中间有个平衡的
                    for (int k = i; k < mid; k++) sb.append(c1);
                    sb.append('.');
                    for (int k = mid + 1; k < j; k++) sb.append(c2);
                } else {
                    for (int k = i; k <= mid; k++) sb.append(c1);
                    for (int k = mid + 1; k < j; k++) sb.append(c2);
                }
            }
            i = j;
        }
        return sb.toString().substring(1);
    }
}
