package com.dezhonger.y2020.m02.d13;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2020/02/13
 *
 * @author dezhonger
 * @since 2020/02/13
 */
public class Leetcode0403 {
    public boolean canCross(int[] stones) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < stones.length; i++) {
            mp.put(stones[i], i);
        }

        int len = stones.length;
        boolean[][] dp = new boolean[len + 5][len + 5];
        dp[0][0] = true;
        boolean find = false;
        for (int i = 0; !find && i < len; i++) {
            for (int j = 0; !find && j <= i; j++) {
                if (dp[i][j]) {
                    if (j != 0) {
                        int nxt1 = stones[i] + j;
                        Integer pos = mp.get(nxt1);
                        if (pos != null) {
                            dp[pos][j] = true;
                            if (pos == len - 1) find = true;
                        }
                    }

                    if (j > 1) {
                        int nxt2 = stones[i] + j - 1;
                        Integer pos = mp.get(nxt2);
                        if (pos != null) {
                            dp[pos][j - 1] = true;
                            if (pos == len - 1) find = true;
                        }
                    }

                    int nxt3 = stones[i] + j + 1;
                    Integer pos = mp.get(nxt3);
                    if (pos != null) {
                        dp[pos][j + 1] = true;
                        if (pos == len - 1) find = true;
                    }
                }
            }
        }
        return find;
    }
}
