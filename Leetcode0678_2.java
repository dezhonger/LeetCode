package com.dezhonger.y2020.m01.d25;

/**
 * Created by dezhonger on 2020/01/25
 *
 * @author dezhonger
 * @since 2020/01/25
 */
public class Leetcode0678_2 {
    public boolean checkValidString(String s) {
        int low = 0, high = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                if (low > 0) low--;
                high--;
            } else {
                if (low > 0) low--;
                high++;
            }
            if (high < 0) return false;
        }
        return 0 == low;
    }
}
