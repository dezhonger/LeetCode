package com.y2019.m12.d01;

import com.y2018.m11.d09.S;

/**
 * Created by zhangweilong on 2019/12/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/01
 */
public class Leetcode1275 {
    public String tictactoe(int[][] moves) {
        int[][] a = new int[3][3];
        int cur = 1;
        String[] users = new String[]{"A", "B", "Draw", "Pending"};
        int step = 0;
        for (int i = 0; i < moves.length; i++) {
            int x = moves[i][0];
            int y = moves[i][1];
            a[x][y] = cur;
            if (check(a, cur)) {
                return users[cur];
            }
            cur = 3 - cur;
            step++;
        }
        return step == 9 ? users[2] : users[3];
    }


    boolean check(int[][] a, int x) {
        for (int i = 0; i < 3; i++) {
            if (a[i][0] == x && a[i][1] == x && a[i][2] == x) return true;
            if (a[0][i] == x && a[1][i] == x && a[2][i] == x) return true;
        }
        if (a[0][0] == x && a[1][1] == x && a[2][2] == x) return true;
        return a[2][0] == x && a[1][1] == x && a[0][2] == x;
    }
}
