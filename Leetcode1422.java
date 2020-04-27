package com.netease.music.leetcode.contest.no186;

/**
 * Created by dezhonger on 2020/04/27
 */
public class Leetcode1422 {
    public int maxScore(String s) {
        int one = 0;
        int zero = 0;
        int ans = 0;
        for (char c : s.toCharArray()) if (c == '1') one++;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '0') zero++;
            else one--;
            ans = Math.max(ans, zero + one);
        }
        return ans;
    }
}
