package com.netease.music.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2019/5/21
 */
public class Leetcode0953 {

    Map<Character, Integer> map = new HashMap<>();

    private int cmp(String value, String anotherString) {
        int len1 = value.length();
        int len2 = anotherString.length();
        int lim = Math.min(len1, len2);
        char v1[] = value.toCharArray();
        char v2[] = anotherString.toCharArray();
        int k = 0;
        while (k < lim) {
            char c1 = v1[k];
            char c2 = v2[k];
            if (c1 != c2) {
                return map.get(c1) - map.get(c2);
            }
            k++;
        }
        return len1 - len2;
    }



    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < order.length(); i++) {
            map.put(order.charAt(i), i);
        }
        for (int i = 1; i < words.length; i++) {
            if (cmp(words[i - 1], words[i]) > 0) {
                return false;
            }
        }
        return true;

    }
}
