package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/12/20
 */
public class Leetcode0713 {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int res =0 ;
        int l = 0;
        int r = 0;
        int ji = 1;
        for (; r < nums.length; r++) {
            ji *= nums[r];
            while (l <= r) {
                if (ji >= k) {
                    ji /= nums[l];
                    l++;
                } else {
                    res +=  r - l + 1;
                    break;
                }
            }
        }
        return res;
    }
}
