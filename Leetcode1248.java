package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/11/28
 */
public class Leetcode1248 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1248().numberOfSubarrays(new int[]{1, 1, 2, 1, 1}, 3));
    }

    public int numberOfSubarrays(int[] nums, int k) {
        int ans = 0;
        int v = 0;
        //每个奇数的左边有几个零
        //001001000 k = 2, list: 2 2 3, 当选择中间的1001的时候，左边的两个0，和最右边的3个0，可以贡献的答案为(2+1)(3+1)
        List<Integer> list = new ArrayList<>();
        for (int x : nums) {
            if (x % 2 == 0) v++;
            else {
                list.add(v);
                v = 0;
            }
        }
        list.add(v);
        for (int i = 0; i < list.size(); i++) {
            if (i + k < list.size()) ans += (list.get(i) + 1) * (list.get(i + k) + 1);
        }
        return ans;
    }
}
