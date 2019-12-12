package com.dezhonger.le;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/12/12
 *
 * @author dezhonger
 * @since 2019/12/12
 */
public class Leetcode0875 {
    public int minEatingSpeed(int[] piles, int H) {
        int l = 1;
        int r = Arrays.stream(piles).max().getAsInt();
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(piles, mid, H)) {
                r = mid;
            } else {
                l = mid + 1;
            }

        }
        return l;
    }

    private boolean check(int[] piles, int mid, int h) {
        int r = 0;
        for (int x : piles) {
            r += (x + mid - 1) / mid;
        }
        return r <= h;
    }
}
