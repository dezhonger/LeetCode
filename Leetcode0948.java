package com.dezhonger.y2020.m01.d26;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/01/26
 *
 * @author dezhonger
 * @since 2020/01/26
 */
public class Leetcode0948 {

    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        int res = 0;
        int point = 0;
        int l = 0, r = tokens.length - 1;
        while (l <= r) {
            if (P >= tokens[l]) {
                point++;
                res = Math.max(res, point);
                P -= tokens[l++];
            } else if (point > 0) {
                point--;
                P += tokens[r--];
            } else {
                break;
            }
        }
        return res;
    }

}
