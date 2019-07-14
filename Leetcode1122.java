package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/7/14
 */
public class Leetcode1122 {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] cnt = new int[1001];
        for (int x : arr1) cnt[x]++;
        int[] r = new int[arr1.length];
        int index = 0;
        for (int x : arr2) {
            for (int j = 0; j < cnt[x]; j++) {
                r[index++] = x;
            }
            cnt[x] = 0;
        }
        for (int x = 0; x < cnt.length; x++) {
            for (int j = 0; j < cnt[x]; j++) {
                r[index++] = x;
            }
        }
        return r;
    }
}
