package com.netease.music.leetcode.hard;

import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2020/05/03
 */
public class Leetcode1434 {
    public static void main(String[] args) {

        System.out.println(new Leetcode1434().numberWays(
                Lists.newArrayList(
                        Lists.newArrayList(3, 4),
                        Lists.newArrayList(4, 5),
                        Lists.newArrayList(5)
                )
        ));
        System.out.println(new Leetcode1434().numberWays(
                Lists.newArrayList(
                        Lists.newArrayList(3, 5, 1),
                        Lists.newArrayList(3, 5)
                )
        ));

        System.out.println(new Leetcode1434().numberWays(
                Lists.newArrayList(
                        Lists.newArrayList(1,2,3,4),
                        Lists.newArrayList(1,2,3,4),
                        Lists.newArrayList(1,2,3,4),
                        Lists.newArrayList(1,2,3,4)
                )
        ));

        System.out.println(new Leetcode1434().numberWays(
                Lists.newArrayList(
                        Lists.newArrayList(1,2,3),
                        Lists.newArrayList(2,3, 5, 6),
                        Lists.newArrayList(1,3,7, 9),
                        Lists.newArrayList(1,8, 9),
                        Lists.newArrayList(2,5,7)
                )
        ));
    }

    public int numberWays(List<List<Integer>> hats) {
        int mod = 10_0000_0007;
        int n = hats.size();
        List<List<Integer>> ha = new ArrayList<>();
        //第i个帽子可以给分配给哪些人
        for (int i = 0; i <= 40; i++) ha.add(new ArrayList<>());

        for (int i = 0; i < n; i++) {
            for (int x : hats.get(i)) {
                ha.get(x).add(i);
            }
        }

        //只考虑前i个帽子用来分配得到的状态为j的方案数，二进制位为1表示这个人被分配过帽子了
        int hatNum = 40;
        int[][] dp = new int[hatNum + 1][1 << n];
        int state = 1 << n;
        dp[0][0] = 1;
        for (int i = 1; i <= hatNum; i++) {
            //第i个帽子可以分配给这些人
            List<Integer> person = ha.get(i);
            //dp[i][j] += dp[i-1][j - (1 << k)] 分配给第k个人


            //第k个帽子不分配
            for (int m = 0; m < state; m++) {
                dp[i][m] += dp[i - 1][m];
                dp[i][m] %= mod;
            }
            //分配给第k个人
            for (int m = 0; m < state; m++) {
                for (int k : person) {
                    if ((m & (1 << k)) > 0) continue;
                    int nxtState = m | (1 << k);
                    dp[i][nxtState] += dp[i - 1][m];
                    dp[i][nxtState] %= mod;
                }
            }
        }
        return dp[hatNum][state - 1];
    }
}
