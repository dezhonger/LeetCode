package com.dezhonger.y2019.m07.d12;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0916 {
    List<String> r = new ArrayList<>();
    List<int[]> a = new ArrayList<>();
    List<int[]> b = new ArrayList<>();
    int[] c = new int[26];
    public List<String> wordSubsets(String[] A, String[] B) {
        for (String s : A) {
            int[] x = new int[26];
            for (char c : s.toCharArray()) {
                x[c - 'a']++;
            }
            a.add(x);
        }
        for (String s : B) {
            int[] x = new int[26];
            for (char c : s.toCharArray()) {
                x[c - 'a']++;
            }
            b.add(x);
        }
        for (int[] x : b) {
            for (int i = 0; i < 26; i++) {
                c[i] = Math.max(c[i], x[i]);
            }
        }
        for (int i = 0; i < A.length; i++) {
            int[] inta = a.get(i);
            boolean f = true;
            for (int j = 0; j < 26; j++) {
                if (inta[j] < c[j]) {
                    f = false;
                    break;
                }
            }

            if (f) r.add(A[i]);
        }
        return r;
    }
}
