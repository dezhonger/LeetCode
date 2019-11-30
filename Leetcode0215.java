package com.y2018.m11.d30;

/**
 * Created by zhangweilong on 2019/11/30
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/11/30
 */
public class Leetcode0215 {

    public int findKthLargest(int[] nums, int k) {
        //kth largest -> n + 1 - k small
        int kth = nums.length + 1 - k;
        int l = 0;
        int r = nums.length - 1;
        while (true) {
            int index = sweep(nums, l, r);
            //在nums[index]左边的数都比nums[index]小 右边都>=nums[index]
            //小于a[index]的个数
            int lessAIndex = index - l;

            //0-base
            if (kth == lessAIndex + 1) {
                return nums[index];
            }
            if (kth <= lessAIndex) {
                //在左边部分找[0, index - 1]继续找第kth小的
                r = index - 1;
            } else {

                //在右边部分找[index + 1, r]继续找kth - index -1小的, 因为在nums[index]左边有lessAIndex个数字(0-base), 已经过滤掉了lessAIndex个数字
                l = index + 1;
                kth = kth - lessAIndex - 1;
            }
        }
    }

    //对数组a[l, l+1, l+2, ..., r]扫描,最后比a[l]小的都在a[l]左边, 大于等于a[l]都在右边, 最后返回的结果是a[l]这个数字最后所在位置的下标
    private int sweep(int[] a, int l, int r) {
        int sentry = a[l];
        while (l < r) {
            while (a[r] >= sentry && r > l) r--;
            if (l < r) swap(a, r, l);
            while (a[l] < sentry && l < r) l++;
            if (l < r) swap(a, l, r);
        }
        return l;
    }

    void swap(int[] a, int x, int y) {
        int t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

}
