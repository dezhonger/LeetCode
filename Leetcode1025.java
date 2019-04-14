package com.netease.music.leetcode.contest.no132;

import java.util.Scanner;

/**
 * Created by dezhonger on 2019/4/14
 */
public class Leetcode1025 {
    public boolean divisorGame(int N) {
        boolean[] dp = new boolean[1005];
        dp[1] = false;
        dp[2] = true;
        dp[3] = false;
        for (int i = 4; i <= N; i++) {
            boolean f = false;
            for (int j = 1; j < i; j++) {
                if(i % j == 0 && !dp[i - j]) {
                    f = true;
                    break;
                }
            }
            dp[i] = f;
        }
        return dp[N];
    }


}
