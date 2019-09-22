
/**
 * Created by dezhonger on 2017/2/10.
 * 给定一个全为非负数的数组，和目标值target，改变数字的符号，使的他们的和为target
 * 求方法数
 *
 *
 * https://leetcode.com/problems/target-sum/?tab=Solutions
 * 设正数集合为P，负数为N
 * sum(P) - sum(N) = target
 * sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
 * 2 * sum(P) = target + sum(nums)
 * sum(P) = [target + sum(nums)] / 2 = k
 * 转化为一个背包问题，在原数组中组合为k的方法数
 */
public class Leetcode0494 {
	public int findTargetSumWays(int[] nums, int target) {
		int sum = 0;
		for (int n : nums)
			sum += n;
		//sum < target 全为正数也不能满足要求
		//(target + sum) % 2 > 0 ,要求的不是整数
		return sum < target || (target + sum) % 2 > 0 ? 0 : subsetSum(nums, (target + sum) >>> 1);
	}

	//背包算法, dp[j]表示组成j的方法数
	public int subsetSum(int[] nums, int s) {
		int[] dp = new int[s + 1];
		dp[0] = 1;
		for (int n : nums)
			for (int i = s; i >= n; i--)
				dp[i] += dp[i - n];
		return dp[s];
	}
}
