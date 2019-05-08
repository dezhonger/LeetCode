package com.dezhonger.y2019.m05;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/05/08
 *
 * @author dezhonger
 * @since 2019/05/08
 */
public class Leetcode0804 {
    String[] s = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    String f(String x) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < x.length(); i++) sb.append(s[x.charAt(i) - 'a']);
        return sb.toString();
    }

    public int uniqueMorseRepresentations(String[] words) {
        Set<String> s = new HashSet<>();
        for (String a : words) {

            s.add(f(a));
        }
        return s.size();
    }
}
