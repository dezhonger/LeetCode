package com.netease.music.p20191013;

/**
 * Created by dezhonger on 2019/10/13
 */
public class Leetcode1221 {
    public int balancedStringSplit(String s) {
        int res = 0;
        int l = 0, r = 0;
        for (char c : s.toCharArray()) {
            if (c == 'L') l++;
            else r++;
            if (l == r) {
                res++;
                l = r = 0;
            }
        }
        return res;
    }
}
