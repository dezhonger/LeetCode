package p1107.p20170213;


/**
 * Created by dezhonger on 2017/2/13.
 * 是环形的，不能取相邻的两个值，求最大和。
 * 分成[0,len-2], [1,len-1]求最大值
 */
public class Leetcode213 {

	public int solve(int[] arr, int a, int b) {
		int n = b - a + 1;
		int[] dp = new int[n];
		dp[0] = arr[a];
		dp[1] = Math.max(arr[a], arr[a + 1]);
		for(int i = 2; i < n; i++) {
			dp[i] = Math.max(dp[i - 1], dp[i - 2] + arr[i + a]);
		}
		return dp[n - 1];
	}

	public int rob(int[] nums) {
		if(nums.length == 0 || nums == null) return 0;
		int len = nums.length;
		if(len == 1) return nums[0];
		if(len == 2) return Math.max(nums[0], nums[1]);
		return Math.max(solve(nums, 0, len - 2), solve(nums, 1, len - 1));
	}
}