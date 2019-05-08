package com.dezhonger.y2019.m05;

/**
 * Created by dezhonger on 2019/05/08
 *
 * @author dezhonger
 * @since 2019/05/08
 */
public class Leetcode0905 {
    public int[] sortArrayByParity(int[] A) {
        int len = A.length;
        int l = 0;
        int r = len - 1;
        while (l < r) {
            while (l < len && A[l] % 2 == 0) l++;
            while (r >= 0 && A[r] % 2 == 1) r--;
            if (l >= len || r < 0 || l >= r) return A;
            int x = A[l];
            A[l] = A[r];
            A[r] = x;
            l++;
            r--;
        }
        return A;
    }
}
