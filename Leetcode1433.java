package com.netease.music.leetcode.contest.bi25;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/05/03
 */
public class Leetcode1433 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1433().checkIfCanBreak("abc", "xya"));
        System.out.println(new Leetcode1433().checkIfCanBreak("abe", "acd"));
        System.out.println(new Leetcode1433().checkIfCanBreak("leetcodee", "interview"));
    }

    public boolean checkIfCanBreak(String s1, String s2) {
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        return c(c1, c2) || c(c2, c1);
    }

    private boolean c(char[] c1, char[] c2) {
        int len = c1.length;
        for (int i = 0; i < len; i++) {
            if (c1[i] > c2[i]) return false;
        }
        return true;
    }
}
