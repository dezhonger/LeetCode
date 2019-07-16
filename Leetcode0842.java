package com.netease.music.p20190716;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0842 {

    Set<Character> set;

    public String toGoatLatin(String S) {
        set = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        StringBuilder sb = new StringBuilder();
        String[] s = S.split(" ");
        for (int i = 0; i < s.length; i++) {
            sb.append(" ");
            sb.append(f(s[i], i + 1));
        }
        return sb.substring(1);
    }

    private String f(String t, int index) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < index; i++) s.append('a');
        if (set.contains(t.charAt(0))) {
            return t + "ma" + s.toString();
        } else {
            return t.substring(1) + t.charAt(0) + "ma" + s.toString();
        }
    }
}
