package leetcode;

/**
 * http://bookshadow.com/weblog/2017/01/22/leetcode-smallest-good-base/
 * Created by Dezhonger on 2017/2/19.
 * 求最低进制n，全为1.
 * 假设当前最高幂次为m , m <= logN(以2位底数)
 * 则，1+k+k^2+...+k^m = n
 * k^m < n < (k+1)^m
 * n^(1/m) - 1 < k < n^(1/m)
 * k = (int)n^(1/m)可能为解
 *
 * 注意到任意一个数N 都可以表示为(N - 1) ^ 0 + (N - 1)^1 = N,即存在N-1为一个答案
 */
public class Leetcode483 {

    public long f(int m, int k) {
        long M = m;
        long K = k;
        long t = 1;
        long r = 1;
        for(int i = 1; i <= m; i++) {
            t *= K;
            r += t;
        }
        return r;

    }

    public String smallestGoodBase(String n) {
        long N = Long.valueOf(n);
        int m = (int)(Math.log(N) / Math.log(2));
        for(int i = m; i > 1; i--) {
            int k = (int)(Math.pow(N, (1.0/i)));
            if(f(i, k) == N) {
                return k+"";
            }
        }
        return (N - 1) + "";
    }

    public static void main(String[] args) {
        System.out.println(new Leetcode483().smallestGoodBase(3+""));
//        System.out.println(new Leetcode483().smallestGoodBase(13+""));
//        System.out.println(new Leetcode483().smallestGoodBase(4681+""));
    }
}
