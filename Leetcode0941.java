package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/21
 */
public class Leetcode0941 {

    private boolean cmp(int a, int b, boolean x) {
        return (x && a < b) || (!x && a > b);
    }

    public boolean validMountainArray(int[] A) {
        if (A.length < 3) return false;
        boolean x = true;
        int index = 1;
        while(index < A.length - 1) {
            if (cmp(A[index-1], A[index], x)) index++;
            else break;
        }
        if (index == 1) return false;
        x = false;
        while(index < A.length) {
            if (cmp(A[index-1], A[index], x)) index++;
            else return false;
        }
        return true;
    }
}
