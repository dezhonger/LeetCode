package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/12/30
 */
public class Leetcode0791 {
    public String customSortString(String S, String T) {
        int[] cnt = new int[26];
        for (char ch : T.toCharArray()) cnt[ch - 'a']++;
        StringBuilder res = new StringBuilder();
        for (char ch : S.toCharArray()) {
            while (cnt[ch - 'a']-- > 0) res.append(ch);
        }
        for (int i = 0; i < cnt.length; i++) {
            while (cnt[i]-- > 0) res.append((char) (i + 'a'));
        }
        return res.toString();
    }
}
