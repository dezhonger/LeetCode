package com.netease.music.p20190730;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/7/30
 */
public class Leetcode0794 {
    public boolean validTicTacToe(String[] board) {
        int a, b;
        char c1, c2;
        a = b = 0;
        c1 = 'X';
        c2 = 'O';
        //分别表示两个人形成横着的，竖着的，斜对角三连个数
        int[] gx = new int[3];
        int[] go = new int[3];
        for (String s : board) {
            if (s.equals("XXX")) gx[0]++;
            if (s.equals("OOO")) go[0]++;
            for (char c : s.toCharArray()) {
                if (c == c1) a++;
                if (c == c2) b++;
            }
        }
        if (b > a) return false;
        if (a - b > 1) return false;

        for (int i = 0; i < 3; i++) {
            if (board[0].charAt(i) == c1 && board[1].charAt(i) == c1 && board[2].charAt(i) == c1) gx[1]++;
            if (board[0].charAt(i) == c2 && board[1].charAt(i) == c2 && board[2].charAt(i) == c2) go[1]++;
        }
        if (board[0].charAt(0) == c1 && board[1].charAt(1) == c1 && board[2].charAt(2) == c1) gx[2]++;
        if (board[0].charAt(0) == c2 && board[1].charAt(1) == c2 && board[2].charAt(2) == c2) go[2]++;
        if (board[0].charAt(2) == c1 && board[1].charAt(1) == c1 && board[2].charAt(0) == c1) gx[2]++;
        if (board[0].charAt(2) == c2 && board[1].charAt(1) == c2 && board[2].charAt(0) == c2) go[2]++;
        //g1, g2分别表示两个人形成三连的个数
        int g1, g2;
        g1 = gx[0] + gx[1] + gx[2];
        g2 = go[0] + go[1] + go[2];
        //不可能俩人同时赢
        if (g1 >= 1 && g2 >= 1) return false;
        //不可能出现横着或竖着的有两个
        if (gx[0] > 1 || gx[1] > 1) return false;
        if (go[0] > 1 || go[1] > 1) return false;
        //a赢的话，棋子个数必须必b多一个
        if (g1 > 0 && a != b + 1) return false;
        //b赢的话，旗子个数必须相等
        if (g2 > 0 && a != b) return false;
        return true;
    }
}
