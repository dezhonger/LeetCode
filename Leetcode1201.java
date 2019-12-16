package com.y2019.m12.d16;

/**
 * Created by zhangweilong on 2019/12/16
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/16
 */
public class Leetcode1201 {
    int n, a, b, c;

    public static void main(String[] args) {
        Leetcode1201 sol = new Leetcode1201();
        System.out.println(sol.nthUglyNumber(3, 2, 3, 5));
        System.out.println(sol.nthUglyNumber(4, 2, 3, 4));
        System.out.println(sol.nthUglyNumber(5, 2, 11, 13));
        System.out.println(sol.nthUglyNumber(1000000000, 2, 217983653, 336916467));
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    long lcm(long a, long b, long c) {
        return lcm(lcm(a, b), c);
    }

    //<=k 有多少个ugly数
    long f(long k) {
        long cnt = k / a + k / b + k / c + k / lcm(a, b, c) - k / lcm(a, b) - k / lcm(a, c) - k / lcm(c, b);
        return cnt;
    }

    long cal(long n) {
        long aa = n / a * a;
        long bb = n / b * b;
        long cc = n / c * c;
        return Math.max(aa, Math.max(bb, cc));
    }

    public int nthUglyNumber(int n, int a, int b, int c) {
        this.n = n;
        this.a = a;
        this.b = b;
        this.c = c;
        long l = 2;
        long r = 20_0000_0000;
        while (l < r) {
            long mid = (l + r) / 2;
            long cnt = f(mid);
            if (cnt == n) {
                return (int) cal(mid);
            }
            if (cnt > n) r = mid - 1;
            else l = mid + 1;
        }
        return (int) cal(l);
    }
}
