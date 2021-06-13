package p1107.p20170210;

/**
 * Created by dezhonger on 2017/2/10.
 * 给一个数组，是否可以分成和相等的两部分
 * 背包算法，dp[j]表示大小为j的背包的最大值
 */
public class Leetcode416 {
	public boolean canPartition(int[] nums) {
		int sum = 0;
		for(int i = 0; i < nums.length; i++) {
			sum += nums[i];
		}
		if(sum % 2 == 1) return false;
		sum /= 2;
		int[] dp = new int[sum + 1];
		for(int i = 0; i < nums.length; i++) {
			for(int j = sum; j >= nums[i] && j >= 0; j--) {
				dp[j] = Math.max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return dp[sum] == sum;
	}

	public static void main(String[] args) {
		int[] x = new int[]{1, 5, 11, 5};
		int[] y = new int[]{2, 4};
		System.out.println(new Leetcode416().canPartition(x));
		System.out.println(new Leetcode416().canPartition(y));
	}
}
