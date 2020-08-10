package com.netease.music.leetcode.contest.bi32;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/08/10
 */
public class Leetcode1542 {
    //"23 4121442"
    public int longestAwesome(String s) {
        int priSum = 0;
        int len = s.length();
        int[] last = new int[1 << 10];
        Arrays.fill(last, 10000000);
        last[0] = -1;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            priSum = priSum ^ (1 << (s.charAt(i) - '0'));
            ans = Math.max(ans, i - last[priSum]);
            //都是偶数个的回文
            last[priSum] = Math.min(last[priSum], i);
            //以数字k为中心的回文
            for (int k = 0; k < 10; k++) {
                ans = Math.max(ans, i - last[priSum ^ (1 << k)]);
            }
        }
        return ans;
    }
}
