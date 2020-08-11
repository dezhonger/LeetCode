package com.y2020.m08.d11;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by zhangweilong on 2020/08/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/08/11
 */
public class Leetcode1546 {
    public int maxNonOverlapping(int[] nums, int target) {
        Map<Long, Integer> mp = new HashMap<>();
        long s = 0;
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            s += nums[i];
            long pre = s - target;
            if (pre == 0) {
                ans++;
                s = 0;
                mp.clear();
            }
            else if (mp.containsKey(pre)) {
                mp.remove(pre);
                ans++;
                s = 0;
                mp.clear();
            } else {
                mp.put(s, i);
            }
        }
        return ans;
    }
}
