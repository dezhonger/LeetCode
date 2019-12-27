package com.y2019.m12.d27;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2019/12/27
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/27
 */
public class Leetcode0881 {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int res = 0;
        int r = people.length - 1;
        int l = 0;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                res++;
                l++;
                r--;
            } else {
                r--;
                res++;
            }
        }
        return res;
    }
}
