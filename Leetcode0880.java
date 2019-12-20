package com.y2019.m12.d20;

import com.y2018.m07.L;

/**
 * Created by zhangweilong on 2019/12/20
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/20
 */
public class Leetcode0880 {

    public String decodeAtIndex(String S, int K) {
        //first, calculate the decode length of S
        long cnt = 0;
        int i = 0;
        for (; i < S.length(); i++) {
            if (Character.isDigit(S.charAt(i))) {
                cnt *= (S.charAt(i) - '0');
            } else {
                cnt++;
            }
            if (cnt >= K) {
                break;
            }
        }

        for (; i >= 0; i--) {

            if (Character.isDigit(S.charAt(i))) {
                int num = S.charAt(i) - '0';
                cnt /= num;
                K %= cnt;
            } else {
                if (K % cnt == 0) {
                    return S.charAt(i) + "";
                }
                cnt--;
            }
        }
        //impossible to reach this
        return "";
    }
}
