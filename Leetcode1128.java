package com.dezhonger.y2019.m07.d21;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by dezhonger on 2019/07/21
 *
 * @author dezhonger
 * @since 2019/07/21
 */
public class Leetcode1128 {
    public static void main(String[] args) {
        new Leetcode1128().numEquivDominoPairs(new int[][]{
                {1, 2},
                {2, 1},
                {3, 4},
                {5, 6},
        });
    }

    public int numEquivDominoPairs(int[][] dominoes) {
        int res = 0;
        for (int[] dominoe : dominoes) {
            if (dominoe[0] <= dominoe[1]) continue;
            int tmp = dominoe[0];
            dominoe[0] = dominoe[1];
            dominoe[1] = tmp;
        }
        Arrays.sort(dominoes, (o1, o2) -> {
            if (o1[0] != o2[0]) return Integer.compare(o1[0], o2[0]);
            return Integer.compare(o1[1], o2[1]);
        });
        int lastx = -1;
        int lasty = -1;
        int cnt = 0;
        for (int i = 0; i < dominoes.length; i++) {
            int x = dominoes[i][0];
            int y = dominoes[i][1];
            if (x == lastx && y == lasty) cnt++;
            else {
                res += cnt * (cnt - 1) / 2;
                cnt = 1;
                lastx = x;
                lasty = y;

            }
        }
        res += cnt * (cnt - 1) / 2;
        return res;
    }
}
