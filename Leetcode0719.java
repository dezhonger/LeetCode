package com.y2020.m01.d29;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2020/02/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/02/29
 */
public class Leetcode0719 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0719().smallestDistancePair(new int[]{1, 3, 1}, 1));
        System.out.println(new Leetcode0719().smallestDistancePair(new int[]{1, 3, 1}, 2));
        System.out.println(new Leetcode0719().smallestDistancePair(new int[]{1, 3, 1}, 3));
    }
    public int smallestDistancePair(int[] nums, int k) {
        int len = nums.length;
        Arrays.sort(nums);

        int l = 0;
        int r = nums[len - 1] - nums[0];
        while (l < r) {
            int mid = (l + r) / 2;

            int cnt = 0;
            int end = 1;
            for (int start = 0; start < len; start++) {
                //第一个和num[start]的差>mid的时候退出循环
                while (end < len && nums[end] - nums[start] <= mid) end++;
                cnt += end - start - 1;
            }

            if (cnt < k) l = mid + 1;
            //因为会有并列的数
//            else if (cnt > k) r = mid;
//            else r = mid;
            //因此可以合并为一句话
            else r = mid;

        }
        return l;
    }



}
