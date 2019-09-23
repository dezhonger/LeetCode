

/**
 * Created by dezhonger on 2017/2/14.
 * 求出x^2+x = 2*n的根，<=这个根的最大值就是结果。
 */
public class Leetcode0441 {

	public int cal(int n) {
		long ans = 0;
		long x = 8L * n + 1;
		long xx = (long)Math.sqrt(x);
		if(xx * xx == x) {
			if((xx - 1) / 2 > 0) {
				return (int)((xx - 1) / 2);
			}
		} else {
			double solve = Math.sqrt(x) - 1;
			solve /= 2;
//			System.out.println(solve);
			return (int)solve;
		}
		return (int)ans;
	}

	public int arrangeCoins(int n) {
		return cal(n);
	}

	public static void main(String[] args) {
//		System.out.println(new Leetcode441().arrangeCoins(10));
//		System.out.println(new Leetcode441().arrangeCoins(15));
//		System.out.println(new Leetcode441().arrangeCoins(11));
//		System.out.println(new Leetcode441().arrangeCoins(12));
//		System.out.println(new Leetcode441().arrangeCoins(13));
		System.out.println(new Leetcode441().arrangeCoins(1804289383));
	}
}
