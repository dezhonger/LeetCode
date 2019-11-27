package com.netease.music.leetcode.design;

/**
 * Created by dezhonger on 2019/11/27
 */
public class Leetcode0201 {
    //其实就是找两个数二进制的公共前缀
    public int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int i = 30;
        while (true) {
            //找到两个数的起始位置
            int bit1 = (m >> i) & 1;
            int bit2 = (n >> i) & 1;
            if (bit1 == 0 && bit2 == 0) i--;
            else break;
        }
        for (; i >= 0; ) {
            int bit1 = (m >> i) & 1;
            int bit2 = (n >> i) & 1;
            if (bit1 == bit2) {
                //位相同, 结果加起来
                res <<= 1;
                res += bit1;
                i--;
            } else {
                //这位不同，说明这位及这位后面的都有0和1出现过了,直接补0就行了
                res <<= (i + 1);
                break;
            }
        }
        return res;
    }
}
