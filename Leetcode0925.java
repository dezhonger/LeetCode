package com.netease.music.p20190716;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0925 {
    public boolean isLongPressedName(String name, String typed) {
        int len1 = name.length();
        int len2 = typed.length();
        if (len2 < len1) return false;

        int l2 = 0;

        char last = 0;
        for (int i = 0; i < len1; ) {
            char c = name.charAt(i);
            if (l2 >= len2) return false;
            char d = typed.charAt(l2);
            if (c == d) {
                l2++;
                i++;
                last = c;
            } else {
                if (d == last) {
                    l2++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
