package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/6/17
 */
public class Leetcode1089 {
    public void duplicateZeros(int[] arr) {
        int[] a = new int[arr.length];
        int index= 0 ;
        for (int i = 0; index < arr.length && i < arr.length; i++) {
            if (arr[i] == 0) {
                a[index++] = 0;
                if (index == arr.length) break;
                a[index++] = 0;
            } else {
                a[index++] = arr[i];
            }
        }
        for (int i = 0; i < arr.length; i++) {
            arr[i] = a[i];
        }
    }
}
