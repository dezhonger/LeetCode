package com.netease.music.p20200207;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by dezhonger on 2020/2/7
 */
public class Leetcode0853 {
    public int carFleet(int target, int[] position, int[] speed) {
        int len = position.length;
        double[][] a = new double[len][2];
        for (int i = 0; i < len; i++) {
            a[i][0] = position[i];
            a[i][1] = 1.0 * (target - position[i]) / speed[i];
        }

        //按照距离从小到大排序
        Arrays.sort(a, Comparator.comparingDouble(o -> o[0]));

        double lastTime = 0;
        int res = 0;
        for (int i = len - 1; i >= 0; i--) {

            if (a[i][1] > lastTime) {
                //下一辆车到达终点时间上一辆车多，那么它自己就是一个车队
                res++;
                lastTime = a[i][1];
            } else {
                //时间比上一辆短，因此可以追上上一辆车，并且合并成一个车队
                //lastTime不需更新，追上以后速度就和上一辆相同
            }
        }
        return res;
    }
}
