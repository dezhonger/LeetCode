package com.y2020.m01.d29;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2020/02/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/02/29
 */
public class Leetcode0689 {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Leetcode0689().maxSumOfThreeSubarrays(new int[]{1, 2, 1, 2, 6, 7, 5, 1}, 2)));
        System.out.println(Arrays.toString(new Leetcode0689().maxSumOfThreeSubarrays(new int[]{1, 2, 1, 2, 2,2,2,2}, 2)));
    }

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int len = nums.length;
        int[] sum = new int[len + 1];
        int[] left = new int[len];
        int[] leftIndex = new int[len];
        int[] right = new int[len];
        int[] rightIndex = new int[len];

        //sum[i]: a[0]+a[1]+...a[i-1]
        for (int i = 0; i < len; i++) sum[i + 1] = sum[i] + nums[i];
        for (int i = 0; i < len; i++) {
            if (i + 1 < k) left[i] = 0;
            else {
                left[i] = sum[i + 1] - sum[i + 1 - k];
                leftIndex[i] = i + 1 - k;
                if (i > 0) {
                    if (left[i - 1] >= left[i]) {
                        left[i] = left[i - 1];
                        leftIndex[i] = leftIndex[i - 1];
                    }
                }

            }
        }
        for (int i = len - 1, j = 0; i >= 0; i--, j++) {
            if (j + 1 < k) right[i] = 0;
            else {
                right[i] = -(sum[i ] - sum[i + k]);
                rightIndex[i] = i;
                if (i < len - 1) {
                    if (right[i + 1] > right[i]) {
                        right[i] = right[i + 1];
                        rightIndex[i] = rightIndex[i + 1];
                    }
                }
            }
        }

        int res = 0;
        int a, b, c;
        a = b = c = -1;
        for (int i = k; i + 2 * k <= len; i++) {
            int s = left[i - 1] + right[i + k] + sum[i  + k] - sum[i ];
            if (s > res) {
                res = s;
                a = leftIndex[i - 1];
                b = i;
                c = rightIndex[i + k];
            }
            res = Math.max(s, res);
        }
//        System.out.println(res);
        return new int[]{a, b, c};

    }
}
