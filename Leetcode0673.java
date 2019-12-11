package com.y2019.m12.d11;

/**
 * Created by zhangweilong on 2019/12/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/11
 */
public class Leetcode0673 {

    public static void main(String[] args) {
        Leetcode0673 sol = new Leetcode0673();
        System.out.println(sol.findNumberOfLIS(new int[]{1, 3, 5, 4, 7}));
//        System.out.println(sol.findNumberOfLIS(new int[]{2,2,2,2,2}));
//        System.out.println(sol.findNumberOfLIS(new int[]{1, 2, 4, 3, 5, 4, 7, 2}));
    }

    public int findNumberOfLIS(int[] nums) {
        int len = nums.length;
        //以第i个数结尾的最大长度
        int[] length = new int[len];
        //以第i个数结尾最大长度的对应序列个数
        int[] cnt = new int[len];
        for (int i = 0; i < len; i++) {
            length[i] = 1;
            cnt[i] =1;
        }
        int maxLength = 1;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 == length[i]) {
                        cnt[i] += cnt[j];
                    } else if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            maxLength = Math.max(maxLength, length[i]);
        }
        int res = 0;
        for (int i = 0; i <  len ;i++) {
            if (length[i] == maxLength) res += cnt[i];
        }
        return res;
    }
}
