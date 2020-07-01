package com.y2020.m07.d01;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2020/07/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/07/01
 */
public class L1486 {
    int m, k;

    public int minDays(int[] bloomDay, int m, int k) {
        int len = bloomDay.length;
        if (len < 1L * m * k) return -1;
        int[] a = new int[len];
        this.m = m;
        this.k = k;
        for (int i = 0; i < len; i++) {
            a[i] = bloomDay[i];
        }
        Arrays.sort(a);
        int l = 0;
        int r = len - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (can(a[mid], bloomDay)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return a[l];
    }

    private boolean can(int x, int[] bloomDay) {
        int cnt = 0;
        int c = 0;
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= x) c++;
            else c = 0;
            if (c == k) {
                c = 0;
                cnt++;
            }
        }
        return cnt >= m;
    }
}
