package com.netease.music.leetcode;

import com.google.common.collect.Lists;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by dezhonger on 2019/12/29
 */
public class Leetcode1301 {
    int n;

    public static void main(String[] args) {
        Leetcode1301 sol = new Leetcode1301();
        System.out.println(Arrays.toString(sol.pathsWithMaxScore(Lists.newArrayList("E23", "2X2", "12S"))));
        System.out.println(Arrays.toString(sol.pathsWithMaxScore(Lists.newArrayList("E12", "1X1", "21S"))));
        System.out.println(Arrays.toString(sol.pathsWithMaxScore(Lists.newArrayList("E11", "XXX", "11S"))));
        System.out.println(Arrays.toString(sol.pathsWithMaxScore(Lists.newArrayList("EX", "XS"))));
    }

    public int[] pathsWithMaxScore(List<String> board) {
        n = board.size();
        int[][] dpSum = new int[n][n];
        int[][] dpCnt = new int[n][n];
        dpCnt[n - 1][n - 1] = 1;
        int[][] d = new int[][]{{-1, 0}, {0, -1}, {-1, -1}};
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board.get(i).charAt(j) == 'X') continue;
                if (dpCnt[i][j] == 0) continue;
                for (int[] dd : d) {
                    int x = i + dd[0];
                    int y = j + dd[1];
                    if (x >= 0 && y >= 0) {
                        char ch = board.get(x).charAt(y);
                        if (ch == 'X') {
                            continue;
                        } else {
                            int v = 0;
                            if (ch != 'E') v = ch - '0';
                            int sum = v + dpSum[i][j];
                            if (sum > dpSum[x][y]) {
                                dpSum[x][y] = sum;
                                dpCnt[x][y] = dpCnt[i][j];
                            } else if (sum == dpSum[x][y]) {
                                dpCnt[x][y] += dpCnt[i][j];
                            }
                            dpCnt[x][y] %= 10_0000_0007;
                        }
                    }
                }
            }
        }
        return new int[]{dpSum[0][0], dpCnt[0][0]};
    }
}
