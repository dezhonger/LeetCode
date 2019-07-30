package com.y2019.m07.d30;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by zhangweilong on 2019/07/30
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/07/30
 */
public class Leetcode0873 {
    public int lenLongestFibSubseq(int[] A) {
        int n = A.length;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < A.length; i++) map.put(A[i], i);
        int[][] f = new int[n][n];
        int res = 0;
        //f[i][j]: 以第i个和第j个数位结尾的时候能得到的数列的元素个数（offset=2）
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n ;j++) {
            Integer index = map.get(A[j] -A[i]);
            if (index != null && index < i) {
                f[i][j] = f[index][i] + 1;
                res = Math.max(res, f[i][j]);
            }
        }
        return res == 0 ? 0 : res + 2;
    }
}
