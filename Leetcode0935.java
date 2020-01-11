package com.y2020.m01.d11;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0935 {


    public int knightDialer(int N) {
        long[][] dp = new long[2][10];
        //init
        Arrays.fill(dp[0], 1);
        int cur = 1;
        int mod = 10_0000_0007;
        for (int i = 2; i <= N; i++) {
            dp[cur][0] = dp[1 - cur][4] + dp[1 - cur][6];
            dp[cur][1] = dp[1 - cur][6] + dp[1 - cur][8];
            dp[cur][2] = dp[1 - cur][7] + dp[1 - cur][9];
            dp[cur][3] = dp[1 - cur][4] + dp[1 - cur][8];

            dp[cur][4] = dp[1 - cur][3] + dp[1 - cur][9] + dp[1 - cur][0];
            dp[cur][5] = 0;
            dp[cur][6] = dp[1 - cur][1] + dp[1 - cur][7] + dp[1 - cur][0];
            dp[cur][7] = dp[1 - cur][2] + dp[1 - cur][6];
            dp[cur][8] = dp[1 - cur][1] + dp[1 - cur][3];
            dp[cur][9] = dp[1 - cur][2] + dp[1 - cur][4];
            dp[cur][0] = dp[1 - cur][4] + dp[1 - cur][6];
            for (int k = 0; k < 10; k++) {
                dp[cur][k] %= mod;
            }
            cur ^= 1;
        }

        long res = 0;
        for (int i = 0; i <= 9; i++) {
            res += dp[1 - N % 2][i];
            res %= mod;
        }
        return (int) res;
    }

}
