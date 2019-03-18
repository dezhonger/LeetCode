package com.dezhonger.y2019.m03;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dezhonger on 2019/03/18
 *
 * @author dezhonger
 * @since 2019/03/18
 */
public class Leetcode1015 {

    static Integer[] digits;
    static int[][] dp = new int[20][1 << 20];


    int numDupDigitsAtMostN(int N) {
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        g(N);
        int result = dfs(digits.length - 1, 0, true, true);
        return 1 + N - result;
    }


    private void g(int x) {

        List<Integer> a = new ArrayList<>();
        while (x > 0) {
            a.add(x % 10);
            x /= 10;
        }

        digits = a.toArray(new Integer[0]);
    }

    /**
     * 记忆化搜索
     *
     * @param index 第i位
     * @param bit   当前已经记录位的结果
     * @param first 是否是当前和之前位的最大数字
     * @param c     前导零
     * @return
     */
    private int dfs(int index, int bit, boolean first, boolean c) {
        if (index < 0) {
            return 1;
        }
        if (!first && dp[index][bit] != -1) {
            return dp[index][bit];
        }
        int ma = first ? digits[index] : 9;
        int sum = 0;
        for (int i = 0; i <= ma; i++) {
            boolean ch = true;
            if (i != 0 || c == false) {
                ch = check(bit, i);
            }
            if (ch) {
                int des = bit;
                if (i != 0 || c == false) {
                    des = bit | (1 << i);
                }
                int s = dfs(index - 1, des, first && i == ma, i == 0 && c);
                sum += s;
            }
        }
        if (!first) {
            dp[index][bit] = sum;
        }
        return sum;
    }

    private boolean check(int bit, int i) {
        return (bit & (1 << i)) == 0;
    }


}
