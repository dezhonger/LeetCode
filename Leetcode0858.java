package com.dezhonger.y2020.m01.d28;

/**
 * Created by dezhonger on 2020/01/29
 *
 * @author dezhonger
 * @since 2020/01/29
 */
public class Leetcode0858 {
    public int mirrorReflection(int p, int q) {
        //find m, n  mp = nq
        while (p % 2 == 0 && q % 2 == 0) {
            p /= 2;
            q /= 2;
        }
        int m = q;
        int n = p;
        //p = 3, q = 2
        //m = 2, n = 3
        //mp = nq

        if (n % 2 == 0)  {
            //n为反射次数+1
            //反射次数是奇数，结果是2号
            return 2;
        }

        return m % 2 == 0 ? 0 : 1;
     }
}
