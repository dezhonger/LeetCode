package com.y2020.m01.d21;

/**
 * Created by zhangweilong on 2020/01/21
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/21
 */
public class Leetcode0640 {
    public static void main(String[] args) {
        new Leetcode0640().solveEquation("x+5-3+x=6+x-2");
    }
    public String solveEquation(String equation) {
        String[] split = equation.split("=", 2);
        int[] l = evaluate(split[0]);
        int[] r = evaluate(split[1]);
        int a = l[0] - r[0];
        int b = r[1] - l[1];
        if (a == 0 && b == 0) return "Infinite solutions";
        if (a == 0 && b != 0) return "No solution";
        return "x=" + (b / a);
    }

    private int[] evaluate(String str) {
        //正向捕获，匹配后面跟着是-或者+的,但不包含这个-或者+
        //x+5-3+x  [x, +5, -3, +x]
        String[] tokens = str.split("(?=[-+])");
        int[] res = new int[2];
        for (String token : tokens) {
            if (token.equals("+x") || token.equals("x")) res[0]++;
            else if (token.equals("-x")) res[0]--;
            else if (token.contains("x")) {
                res[0] += Integer.parseInt(token.substring(0, token.length() - 1));
            } else {
                res[1] += Integer.parseInt(token);
            }
        }
        return res;
    }
}
