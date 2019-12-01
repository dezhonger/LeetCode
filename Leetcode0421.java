package com.y2019.m11.d30;

import com.y2018.m07.L;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by zhangweilong on 2019/12/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/01
 */
public class Leetcode0421 {

    public static void main(String[] args) {
        Leetcode0421 sol = new Leetcode0421();
        sol.findMaximumXOR(new int[]{2, 3, 5, 8, 10, 25});
    }

    public int findMaximumXOR(int[] nums) {
        int res = 0;
        for (int i = 4; i >= 0; i--) {
            int mask = 1 << i;
            res |= mask;
            Set<Integer> set = new HashSet<>();
            for (int x : nums) set.add(x & res);
            boolean f = false;
            for (int x : set) {

                if (set.contains(x ^ res)) {
                    //该位能取到1
                    f = true;
                    break;
                }
            }
            //该位取不到1,置为0
            if (!f) res ^= mask;
        }
        return res;
    }
}
