package com.y2020.m01.d11;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0926 {
    public int minFlipsMonoIncr(String S) {
        int[] one = new int[S.length() + 1];
        int[] zero = new int[S.length() + 1];
        for (int i = 0; i < S.length(); i++) {
            one[i + 1] = one[i];
            zero[i + 1] = zero[i];
            if (S.charAt(i) == '0') one[i + 1]++;
            else zero[i + 1]++;
        }
        int allZero = zero[S.length()];
        int allOne = one[S.length()];

        int result = Integer.MAX_VALUE;
        for (int i = 0; i <= S.length(); i++) {
            int res = 0;
            //前i个是需要把1变为0的
            res += i - one[i];
            //后面的需要把0变为1的
            res += S.length() - i - (allZero - zero[i]);
            result = Math.min(result, res);
        }
        return result;
    }
}
