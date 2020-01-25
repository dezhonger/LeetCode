package com.dezhonger.y2020.m01.d25;

import java.util.Random;

/**
 * Created by dezhonger on 2020/01/25
 *
 * @author dezhonger
 * @since 2020/01/25
 * Leetcode0528
 */
public class Leetcode0528 {
    int[] s;
    int sum = 0;
    Random random;
    public Leetcode0528(int[] w) {
        s = new int[w.length + 1];
        for (int i = 0; i < w.length; i++) {
            s[i + 1] = s[i] + w[i];
            sum += w[i];
        }
        random = new Random();
    }

    public int pickIndex() {
        int x = random.nextInt(sum);
        int l = 1;
        int r = s.length;
        while(l < r) {
            int mid = (l + r) / 2;
            //下标从1开始，所以减1
            if (x < s[mid] && x >= s[mid - 1]) return mid - 1;

            if (x >= s[mid]) l = mid + 1;
            else r = mid - 1;
        }
        return r - 1;
    }
}
