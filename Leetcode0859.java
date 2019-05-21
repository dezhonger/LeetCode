package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/5/21
 */
public class Leetcode0859 {
    public boolean buddyStrings(String A, String B) {
        int len1 = A.length();
        int len2 = A.length();
        if (len1 != len2) return false;
        List<Integer> list = new ArrayList<>();
        int[] cnt = new int[26];
        for (int i = 0; i < len1; i++) {
            if (A.charAt(i) != B.charAt(i)) list.add(i);
            cnt[A.charAt(i) - 'a']++;
        }

        int size = list.size();
        if (size > 2) return false;
        if (size == 1) {
            return false;
        } else if (size == 2) {
            int a = list.get(0);
            int b = list.get(1);
            return A.charAt(a) == B.charAt(b) && A.charAt(b) == B.charAt(a);
        } else {
            //size = 0
            for (int x : cnt) if (x > 1) return true;
            return false;
        }

    }
}
