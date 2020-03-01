package com.y2020.m03.d01;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by zhangweilong on 2020/03/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/03/01
 */
public class Leetcode0446 {

    public static void main(String[] args) {
        Leetcode0446 sol = new Leetcode0446();
//        sol.numberOfArithmeticSlices(new int[]{2, 4, 6, 8, 10});
//        sol.numberOfArithmeticSlices(new int[]{2, 2, 3, 4});
        sol.numberOfArithmeticSlices(new int[]{2, 3, 4});
        sol.numberOfArithmeticSlices2(new int[]{0,2000000000,-294967296});
    }

    public int numberOfArithmeticSlices(int[] A) {
        int len = A.length;

        int[][] dp = new int[len][1000010];
        //dp[i][d] 以 num[i]结尾的差为d等差数列的个数,这个等差数列长度至少为2
        int res = 0;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                //求出公差
                int diff = A[i] - A[j];

                //以nums[i]结尾的公差为diff的长度为>=2的等差数列可以由两种方式得来

                //1: (nums[j], nums[i]）可以构成一个公差为diff的长度为2的等差数列
                //2:  dp[j][diff]表示以nums[j]公差为diff的长度为2的等差数列，我们在其后面加上一个nums[i]，便可以构成长度>=3的等差数列
                //    我们可以把这部分累加到最终的答案里，因为题目要求等差数列的长度至少为3
                dp[i][diff] += 1;
                dp[i][diff] += dp[j][diff];

                res += dp[j][diff];
            }
        }
        return res;
    }


    public int numberOfArithmeticSlices2(int[] A) {
        int len = A.length;

        Map<Long, Integer>[] dp = new Map[len];
        //dp[i].get(d) 以 num[i]结尾的差为d等差数列的个数,这个等差数列长度至少为2
        int res = 0;

        for (int i = 0; i < len; i++) {
            dp[i] = new HashMap<>(i);
            for (int j = 0; j < i; j++) {
                //求出公差
                long diff = (long)A[i] - A[j];
                if (diff <= Integer.MIN_VALUE || diff >= Integer.MAX_VALUE) continue;
                //以nums[i]结尾的公差为diff的长度为>=2的等差数列可以由两种方式得来

                //1: (nums[j], nums[i]）可以构成一个公差为diff的长度为2的等差数列
                //2:  dp[j].get(diff) 表示以nums[j]公差为diff的长度为2的等差数列，我们在其后面加上一个nums[i]，便可以构成长度>=3的等差数列
                //    我们可以把这部分累加到最终的答案里，因为题目要求等差数列的长度至少为3
                int v = dp[i].getOrDefault(diff, 0);
                int add = dp[j].getOrDefault(diff, 0);
                v += add + 1;
                res += add;
                dp[i].put(diff, v);
            }
        }
        return res;
    }
}
