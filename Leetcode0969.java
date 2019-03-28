package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/3/28
 */
public class Leetcode0969 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0969().pancakeSort(new int[]{3,2,4,1}));
    }

    public List<Integer> pancakeSort(int[] A) {
        List<Integer> r = new ArrayList<>();
        int len = A.length;
        for (int i = len; i > 1; i--) {
            if (A[i - 1] == i) continue;
            int index = 0;
            for (int j = len - 1; j >= 0; j--) if (A[j] == i) index = j;
            r.add(index + 1);
            for (int k1 = 0, k2 = index; k1 < k2; k1++,k2--) {
                int tmp = A[k1];
                A[k1] = A[k2];
                A[k2] = tmp;
            }
            for (int k1 = 0, k2 = i - 1; k1 < k2; k1++,k2--) {
                int tmp = A[k1];
                A[k1] = A[k2];
                A[k2] = tmp;
            }
            r.add(i);
        }
        return r;
    }
}
