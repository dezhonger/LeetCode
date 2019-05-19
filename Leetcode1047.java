package com.netease.music.leetcode.contest.no137;

/**
 * Created by dezhonger on 2019/5/19
 */
public class Leetcode1047 {
    public static void main(String[] args) {
        new Leetcode1047().removeDuplicates("abbaca");
//        new Leetcode1047().removeDuplicates("aaaaaaaa");
//        new Leetcode1047().removeDuplicates("aaa");
    }
    public String removeDuplicates(String S) {
        StringBuilder sb = new StringBuilder();
        int c = -1;
        for (int i = 0; i < S.length(); i++) {
            if (c >= 0 && S.charAt(i) == sb.charAt(c)) {
                sb.deleteCharAt(c);
                c--;
            }
            else {
                sb.append(S.charAt(i));
                c++;
            }
        }
        return sb.toString();

    }
}
