package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/7/11
 */
public class Leetcode0844 {
    public static void main(String[] args) {
        new Leetcode0844().backspaceCompare("ab#c", "ad#c");
    }
    public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1;
        int j = T.length() - 1;

        char sNext = S.charAt(i);
        char tNext = T.charAt(j);
        int sBack = 0;
        int tBack = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && ((sNext = S.charAt(i)) == '#' || sBack > 0)) {
                if (sNext == '#') sBack++;
                else sBack--;
                i--;
            }
            while (j >= 0 && ((tNext = T.charAt(j)) == '#' || tBack > 0)) {
                if (tNext == '#') tBack++;
                else tBack--;
                j--;
            }
            if (i >= 0 && j >= 0 && sNext != tNext) return false;
            else if (i < 0 && j >= 0) return false;
            else if (i >= 0 && j < 0) return false;
            i--;
            j--;
        }

        return true;
    }


}
