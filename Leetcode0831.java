package com.dezhonger.y2020.m02.d10;

/**
 * Created by dezhonger on 2020/02/10
 *
 * @author dezhonger
 * @since 2020/02/10
 */
public class Leetcode0831 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0831().maskPII("AB@qq.com"));
        System.out.println(new Leetcode0831().maskPII("1(234)567-890"));
        System.out.println(new Leetcode0831().maskPII("86-(10)12345678"));
    }

    public String maskPII(String S) {
        if (S.contains("@")) {
            return formatEmail(S);
        } else {
            return formatPhoneNumber(S);
        }
    }

    private String formatEmail(String s) {
        s = s.toLowerCase();
        int index = s.indexOf('@');
        String sub = s.substring(0, index);
        StringBuilder sb = new StringBuilder();
        sb.append(sub.charAt(0));
        sb.append("*****");
        sb.append(sub.charAt(sub.length() - 1));
        sb.append(s.substring(index));
        return sb.toString();
    }

    private String formatPhoneNumber(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') continue;
            if (s.charAt(i) == ')') continue;
            if (s.charAt(i) == ' ') continue;
            if (s.charAt(i) == '-') continue;
            if (s.charAt(i) == '+') continue;
            sb.append(s.charAt(i));
        }

        int n = sb.length();

        StringBuilder res = new StringBuilder();
        if (n > 10) {
            res.append("+");
            for (int i = 0; i < n - 10; i++) res.append("*");
            res.append("-");
        }
        res.append("***-***-");
        res.append(sb.toString().substring(n - 4));
        return res.toString();

    }
}
