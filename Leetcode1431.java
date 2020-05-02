package com.netease.music.leetcode.contest.bi25;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2020/05/03
 */
public class Leetcode1431 {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> res = new ArrayList<>();
        int num = -1;
        for (int i = 0; i < candies.length; i++) {
            if (candies[i] > num) {
                num = candies[i];
            }
        }
        for (int i = 0; i < candies.length; i++) {
            if (candies[i] + extraCandies >= num) res.add(true);
            else res.add(false);
        }
        return res;
    }
}
