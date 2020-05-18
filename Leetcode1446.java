package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2020/05/18
 */
public class Leetcode1446 {
    public int maxPower(String s) {
        int res = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int j = i;
            while (i + 1 < len && s.charAt(i) == s.charAt(i + 1)) i++;
            res = Math.max(i - j + 1, res);
        }
        return res;
    }
}
