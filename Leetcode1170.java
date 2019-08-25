//package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/8/25
 */
public class Leetcode1170 {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] c = new int[12];
        for (String word : words) {
            int h = f(word);
            c[h]++;
        }
        for (int i = 9; i >= 0; i--) c[i] += c[i + 1];
        int[] r = new int[queries.length];
        for (int i = 0; i < queries.length; i++) r[i] = c[f(queries[i]) + 1];
        return r;
    }

    private int f(String s) {
        int[] c = new int[26];
        for (char ch : s.toCharArray()) c[ch - 'a']++;
        for (int i = 0; i < 26; i++) if (c[i] > 0) return c[i];
        return -1;
    }
}
