package com.dezhonger.y2019.m11.d27;

/**
 * Created by dezhonger on 2019/11/27
 *
 * @author dezhonger
 * @since 2019/11/27
 */
public class Leetcode1224_2 {
    public int maxEqualFreq(int[] nums) {
        //每个数出现的次数
        int[] f = new int[100005];
        //每个次数出现的次数
        int[] ff = new int[100005];
        ff[0] = 100000;
        int ans = 0;
        //每个数出现的次数的最大值
        int max = 0;
        //出现过的数的个数
        int stand = 0;
        for (int i = 0; i < nums.length; i++) {
            int v = nums[i];
            ff[f[v]]--;
            f[v]++;
            if (f[v] == 1) stand++;
            max = Math.max(max, f[v]);
            ff[f[v]]++;

            if (ok(ff, max, stand)) {
                ans = i + 1;
            }
        }
        return ans;
    }

    boolean ok(int[] ff, int max, int stand) {
        //所有数都出现了一次
        if (max == 1) return true;
        //出现次数最大值对应的只有一个数
        if (ff[max] == 1) {
            //只有一个数 (11111)
            if (stand == 1) return true;
            //有两个数 并且出现一次的数的数量为1 (1 555555)
            if (stand == 2 && ff[1] == 1) return true;
            //最多次数的那个数 他出现次数为max次, 其余所有的数出现的次数为max-1次 可以等价为下面的式子，就是说，除了最多的次数(max)的那个数外，出现次数为max-1的数的个数为(总数-1)个
            //例子： 222333444555 6666 这里max=4, stand=5
            if (ff[max - 1] == stand - 1) return true;
            return false;
        }

        //除了某个数外, 所有数都出现了相同的次数 , 所谓的某个数,他只出现了一次  例子:(1112223334445),某个数就是5
        if (ff[max] == stand - 1 && ff[1] == 1) return true;
        return false;
    }
}
