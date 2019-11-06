package com.y2019.m11.d06;

/**
 * Created by zhangweilong on 2019/11/06
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/11/06
 */
public class Leetcode1250 {
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public boolean isGoodArray(int[] nums) {
        int r = nums[0];
        for (int x : nums) r = gcd(r, x);
        return 1 == r;
    }
}
