package com.netease.music.leetcode.contest.bi25;

/**
 * Created by dezhonger on 2020/05/03
 */
public class Leetcode1432 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1432().maxDiff(555));
        System.out.println(new Leetcode1432().maxDiff(9));
        System.out.println(new Leetcode1432().maxDiff(123456));
        System.out.println(new Leetcode1432().maxDiff(10000));
        System.out.println(new Leetcode1432().maxDiff(9288));
    }
    public int maxDiff(int num) {
        String s = num + "";
        int a = Integer.MIN_VALUE, b = Integer.MAX_VALUE;
        for (char i = '0'; i <= '9'; i++) {
            for (char j = '0'; j <= '9'; j++) {
                String n = s.replace(i, j);
                if (n.charAt(0) == '0') continue;
                a = Math.max(a, Integer.parseInt(n));
                b = Math.min(b, Integer.parseInt(n));
            }
        }
        return a - b;
    }
}
