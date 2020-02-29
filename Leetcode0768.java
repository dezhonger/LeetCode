package com.y2020.m01.d29;

/**
 * Created by zhangweilong on 2020/02/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/02/29
 */
public class Leetcode0768 {
    public int maxChunksToSorted(int[] arr) {
        int len = arr.length;
        int[] mi = new int[len];
        mi[len - 1] = arr[len - 1];
        for (int i = len - 2; i >= 0; i--) mi[i] = Math.min(arr[i], mi[i + 1]);
        int res = 0;
        int ma = 0;
        for (int i = 0; i < len; i++) {
            ma = Math.max(ma, arr[i]);
            if (i == len - 1 || mi[i + 1] >= ma) res++;
        }
        return res;
    }
}
