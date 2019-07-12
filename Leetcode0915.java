package com.dezhonger.y2019.m07.d12;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0915 {
    public int partitionDisjoint(int[] A) {
        int[] ma = new int[A.length];
        int[] mi = new int[A.length];
        ma[0] = A[0];
        mi[A.length - 1] = A[A.length - 1];
        for (int i = 1; i < A.length; i++) ma[i] = Math.max(A[i], ma[i - 1]);
        for (int i = A.length - 2; i >= 0; i--) mi[i] = Math.min(A[i], mi[i + 1]);
        for (int i = 0; i < A.length - 1; i++) {
            if (ma[i] <= mi[i + 1]) return i + 1;
        }
        return 0;
    }
}
