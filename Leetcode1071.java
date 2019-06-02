package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/6/3
 */
public class Leetcode1071 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1071().gcdOfStrings("abcabc", "abc"));
    }
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    boolean check(String s1, String s2, int g) {
        String s = s1.substring(0, g);
        if (check(s, s1) && check(s, s2)) return true;
        return false;
    }

    private boolean check(String s, String s1) {
        int g = s.length();
        for (int i = 0; i < s1.length(); i += g) {
            if (!s.equals(s1.substring(i, i + g))) {
                return false;
            }
        }
        return true;
    }


    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int g = gcd(len1, len2);
        int res = 0;
        for (int i = g; i >= 1; i--) {
            if (g % i == 0 && check(str1, str2, i)) {
                res = Math.max(res, i);
                break;
            }
        }
        if (res == 0) return "";
        else return str1.substring(0, res);
    }
}
