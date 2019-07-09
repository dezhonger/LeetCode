package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/7/4
 */
public class Leetcode1106 {
    public static void main(String[] args) {
        boolean s = new Leetcode1106().parseBoolExpr("|(f,t)");
        System.out.println(s);
    }

    char[] s;
    int len, pos;

    public boolean parseBoolExpr(String expression) {
        s = expression.toCharArray();
        len = s.length;
        pos = 0;

        boolean res = expr();
        assert pos == len;
        return res;
    }

    private boolean expr() {
        if (s[pos] == 't') {
            pos++;
            return true;
        }

        if (s[pos] == 'f') {
            pos++;
            return false;
        }

        if (s[pos] == '!') {
            pos++;
            assert s[pos] == '(';
            pos ++;
            boolean res = expr();
            assert s[pos] == ')';
            pos++;
            return !res;
        }

        if (s[pos] == '&') {
            pos++;
            assert s[pos] == '(';
            pos++;
            boolean q = true;
            while (true) {
                boolean res = expr();
                q &= res;
                if (s[pos] == ')') break;
                assert s[pos] == ',';
                pos++;
            }
            pos++;
            return q;
        }

        if (s[pos] == '|') {
            pos++;
            assert s[pos] == '(';
            pos++;
            boolean q = false;
            while (true) {
                boolean res = expr();
                q |= res;
                if (s[pos] == ')') break;
                assert s[pos] == ',';
                pos++;
            }
            pos++;
            return q;
        }
        throw new RuntimeException("" + pos);
    }
}
