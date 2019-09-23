package p1107.p20170213;

/**
 * Created by dezhonger on 2017/2/13.
 * 一列数组，每次没人都必须从两头取值,谁多谁胜
 * solve(num, a, b)表是从这个数组先拿比后拿多的值
 *
 */
public class Leetcode0486 {

	public int solve(int[] num, int a, int b) {
		if(a == b) return num[a];
		int result1 = num[a] - solve(num, a + 1, b); //拿左边的
		int result2 = num[b] - solve(num, a, b + 1); //拿右边的
		return Math.max(result1, result2);
	}

	public boolean PredictTheWinner(int[] nums) {
		return solve(nums, 0, nums.length - 1) >= 0;
	}
}
