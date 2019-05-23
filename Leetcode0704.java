package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/23
 */
public class Leetcode0704 {

    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        if (nums[l] == target) {
            return l;
        }
        return -1;
    }
}
