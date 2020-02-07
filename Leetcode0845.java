package com.dezhonger.y2020.m02.d07;

/**
 * Created by dezhonger on 2020/02/07
 *
 * @author dezhonger
 * @since 2020/02/07
 */
public class Leetcode0845 {
    public int longestMountain_followup(int[] A) {
        int up = 0, down = 0, res = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i - 1] < A[i] && down > 0) up = down = 0;
            if (A[i - 1] == A[i]) up = down = 0;
            if (A[i - 1] < A[i]) up++;
            if (A[i - 1] > A[i]) down++;
            if (up > 0 && down > 0) res = Math.max(res, up + down + 1);
        }
        return res;
    }


    public int longestMountain(int[] A) {
        int len = A.length;
        int[] l = new int[len];
        int[] r = new int[len];
        l[0] = 1;
        for (int i = 1; i < len; i++) {
            l[i] = A[i] > A[i - 1] ? l[i - 1] + 1 : 1;
        }

        r[len - 1] = 1;
        for (int i = A.length - 2; i >= 0; i--) {
            r[i] = A[i] > A[i + 1] ? r[i + 1] + 1 : 1;
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            if (l[i] >= 2 && r[i] >= 2) res = Math.max(res, l[i] + r[i] - 1);
        }
        return res;
    }
}
