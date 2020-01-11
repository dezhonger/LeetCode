package com.y2020.m01.d11;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0769 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0769().maxChunksToSorted(new int[]{1,0,2,3,4}));
    }
    public int maxChunksToSorted(int[] arr) {
        int res = 0;
        int max = 0;
        for (int i = 0; i < arr.length; i++){
            max = Math.max(max, arr[i]);
            if (max == i) res++;
        }
        return res;
    }
}
