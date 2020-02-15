package com.dezhonger.y2020.m02.d15;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/02/15
 *
 * @author dezhonger
 * @since 2020/02/15
 */
public class Leetcode1040 {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int[] res = new int[2];
        //在第一个格子和最后一个格子之间一共有多少个空位
        int space = stones[n - 1] - stones[0] - 1 - (n - 2);


        //我们先求最大值

        //我们把第一个数移动到第二个数之后，然后剩下的空位都是可以用掉的（除了第一个和第二个数之间的空位)
        int m1 = space - (stones[1] - stones[0] - 1);
        //我们把第倒数一个数移动到倒数第二个数之前，然后剩下的空位都是可以用掉的（除了第一个和第二个数之间的空位)
        int m2 = space - (stones[n - 1] - stones[n - 2] - 1);
        res[1] = Math.max(m1, m2);

        //接下来求最小值,枚举最后n个石头所在的区间
        int l = 0;
        int mi = Integer.MAX_VALUE;
        for (int r = 0; r < n; r++) {
            while (stones[r] - stones[l] + 1 > n) l++;
            //从l到r一共有多少个石头
            int num = r - l + 1;
            //一共五个石头, 2 3 4 5  10 我们枚举到l=0, r=3这种情况虽然区间内有4个石头，但是需要移动两次才能得到答案
            if (num == n - 1 && stones[r] - stones[l] == n - 2) mi = Math.min(mi, 2);
            //移动次数为不在这个这个区间的石头数，关于这个点，我觉得还是有点复杂的
            //比如2 3 4 5  10 20,l=0 r=3, 不在区间的石头数为2，方案：先把20移动到7，然后把10移动到6，恰好正确
            //但是2 3 4 5 7 20,l=0 r=3, 不在区间的石头数为2，但是我们移动一次就能得到答案了，不正确， 不过呢，我们在枚举
            //到后面的区间的时候 l = 0, r=4,是会修复掉这个情况的
            else mi = Math.min(mi, n - num);
        }
        res[0] = mi;
        return res;
    }
}
