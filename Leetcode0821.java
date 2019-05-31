package com.dezhonger.y2019.m06.d01;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/05/31
 *
 * @author dezhonger
 * @since 2019/05/31
 */
public class Leetcode0821 {
    public int[] shortestToChar(String S, char C) {
        char[] chars = S.toCharArray();
        int[] r = new int[chars.length];
        int last = 200000;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == C) {
                last = 0;
                r[i] = 0;
            } else {
                r[i] = last + 1;
                last++;
            }
        }
        last = 200000;
        for (int i = chars.length - 1; i >= 0; i--) {
            if (chars[i] == C) {
                last = 0;
                r[i]= 0;
            } else {
                r[i] = Math.min(r[i], last + 1);
                last++;
            }
        }
        return r;
    }
}
