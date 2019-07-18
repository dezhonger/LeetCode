package com.netease.music.rep2.dolphin.job.task;


/**
 * Created by dezhonger on 2019/07/18
 *
 * @author dezhonger
 * @since 2019/07/18
 */
public class Leetcode0906 {


    boolean f(long x) {
        String s = x + "";
        int l = s.length();
        for (int i = 0; i < l; i++) if (s.charAt(i) != s.charAt(l - i - 1)) return false;
        return true;
    }

    long g1(String x) {
        StringBuffer sb = new StringBuffer(x);
        int len = x.length();
        for (int i = 0; i < x.length(); i++) {
            sb.append(x.charAt(len - i - 1));
        }
        return Long.valueOf(sb.toString());
    }

    long g2(String x) {
        StringBuffer sb = new StringBuffer(x);
        int len = x.length();
        for (int i = 1; i < x.length(); i++) {
            sb.append(x.charAt(len - i - 1));
        }
        return Long.valueOf(sb.toString());
    }

    public int superpalindromesInRange(String L, String R) {
        int r = 31623;
        int res = 0;
        long LL = Long.valueOf(L);
        long RR = Long.valueOf(R);
        for (int i = 1; i <= r; i++) {
            long a = g1(i + "");
            long b = g2(i + "");
            a = a * a;
            b = b * b;
            if (f(a) && check(LL, RR, a)) {
                res++;
            }
            if (f(b) && check(LL, RR, b)) {
                res++;
            }

        }
        return res;
    }

    private boolean check(long ll, long rr, long a) {
        return ll <= a && a <= rr;
    }
}
