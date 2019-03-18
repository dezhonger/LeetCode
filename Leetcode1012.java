package com.dezhonger.y2019.m03;

/**
 * Created by dezhonger on 2019/03/18
 *
 * @author dezhonger
 * @since 2019/03/18
 */
public class Leetcode1012 {

    public static void main(String[] args) {
        System.out.println(new Leetcode1012().bitwiseComplement(5));
        System.out.println(new Leetcode1012().bitwiseComplement(7));
        System.out.println(new Leetcode1012().bitwiseComplement(10));
    }
    public int bitwiseComplement(int N) {
        String s = Integer.toBinaryString(N);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) sb.append(f(s.charAt(i)));
        return Integer.parseInt(sb.toString(), 2);
    }

    private char f(char charAt) {
        if (charAt == '0') return '1';
        return '0';
    }
}
