package com.netease.music.leetcode;

import java.math.BigInteger;

/**
 * Created by dezhonger on 2019/4/3
 */
public class Leetcode0972 {
    public static void main(String[] args) {
        Leetcode0972 code = new Leetcode0972();
//        System.out.println(code.isRationalEqual("0.(52)", "0.5(25)"));
//        System.out.println(code.isRationalEqual("0.1666(6)", "0.166(66)"));
//        System.out.println(code.isRationalEqual("0.9(9)", "1."));
//        System.out.println(code.isRationalEqual("0.9(9)", "1"));
//        System.out.println(code.isRationalEqual("1.0", "1"));
//        System.out.println(code.isRationalEqual("0.(0)", "0"));
        System.out.println(code.isRationalEqual("0.08(9)", "0.09"));
    }


    public boolean isRationalEqual(String S, String T) {
        int index1 = S.indexOf(".");
        int index2 = T.indexOf(".");
        //如果都是整数，直接比较
        if (index1 == -1 && index2 == -1) return S.equals(T);

        if (index2 == -1) {
            //第二个数没有小数部分
            int z1 = Integer.valueOf(S.substring(0, index1));
            int z2 = Integer.valueOf(T);
            if (z1 == z2 && p(S.substring(index1 + 1))) return true;
            if (z1 + 1 == z2 && g(S.substring(index1 + 1))) return true;
            else return false;
        }
        if (index1 == -1) {
            //第一个数没有小数部分
            int z1 = Integer.valueOf(S);
            int z2 = Integer.valueOf(T.substring(0, index2));
            if (z1 == z2 && p(T.substring(index2 + 1))) return true;
            if (z2 + 1 == z1 && g(T.substring(index2 + 1))) return true;
            else return false;
        }

        //特殊处理，如果整数部分相差1，较小的数的小数部分等于1
        int z1 = Integer.valueOf(S.substring(0, index1));
        int z2 = Integer.valueOf(T.substring(0, index2));
        if (z1 == z2 + 1 && g(T.substring(index2 + 1))) {
            return true;
        }
        if (z2 == z1 + 1 && g(S.substring(index1 + 1))) {
            return true;
        }

        //比较整数部分和下小数部分
        if (!S.substring(0, index1).equals(T.substring(0, index2))) {
            //整数部分不相等
            return false;
        }
        String x1 = S.substring(index1 + 1);
        String x2 = T.substring(index2 + 1);
        BigInteger[] b1 = f(x1);
        BigInteger[] b2 = f(x2);
        return compare(b1, b2);


    }

    private boolean compare(BigInteger[] b1, BigInteger[] b2) {
        BigInteger x = b1[0].multiply(b2[1]);
        BigInteger y = b1[1].multiply(b2[0]);
        return x.compareTo(y) == 0;
    }

    private BigInteger[] f(String s) {
        int index1 = s.indexOf("(");
        int index2 = s.indexOf(")");

        BigInteger a;
        BigInteger b;
        if (index1 == -1) {
            a = new BigInteger(s);
            StringBuilder sb = new StringBuilder("1");
            for (int i = 0; i < s.length(); i++) sb.append(0);
            b = new BigInteger(sb.toString());
            return new BigInteger[]{a, b};
        } else {
            if (index1 == 0) {
                a = BigInteger.ZERO;
            } else {
                a = new BigInteger(s.substring(0, index1));
            }
            b = new BigInteger(s.replace("(", "").replace(")", ""));
            BigInteger fenzi = b.subtract(a);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < index2 - index1 - 1; i++) sb.append(9);
            for (int i = 0; i < index1; i++) sb.append(0);
            BigInteger fenmu = new BigInteger(sb.toString());
            return new BigInteger[]{fenzi, fenmu};
        }


    }

    //判断小数部分是否是0.9,9循环
    private boolean g(String s) {
        if (!s.contains("(")) return false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') continue;
            if (s.charAt(i) != '9') return false;
        }
        return true;
    }

    //判断小数部分是不是0
    private boolean p(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') continue;
            if (s.charAt(i) != '0') return false;
        }
        return true;
    }

}
