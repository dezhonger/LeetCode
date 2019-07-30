package com.netease.music.p20190730;

/**
 * Created by dezhonger on 2019/7/30
 */
public class Leetcode0795 {
    //计算最大值<=r的子数组的个数
    private int f(int[] A, int r) {
        int c = 0;
        int res = 0;
        for (int x : A) {
            //c表示以x结尾的子数组个数，满足最大值<=r
            if (x <= r) c++;
            else c = 0;
            res += c;
        }
        return res;
    }

    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        //最大值<=L的子数组，是最大值<=R的子数组的子集，相减就是最大值在[L, R]的子数组
        return f(A, R) - f(A, L - 1);
    }
}
