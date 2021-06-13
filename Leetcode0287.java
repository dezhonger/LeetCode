package p1107.p20170222;

/**
 * Created by dezhonger on 2017/2/22.
 * 一个长度为n+1的数组里面的数字满足1<=x<=n其中有一个数字出现了很多次，求这个数字
 * 二分要找的数字，O(nlgn)
 * 有O(n)的解法。可以学习一下
 */
public class Leetcode287 {

	public int cnt(int[] nums, int x) {
		int c = 0;
		for(int a : nums) {
			c += a <= x ? 1 : 0;
		}
		return c;
	}

	public int findDuplicate(int[] nums) {
		int len = nums.length;
		//len >= 2, 1 <= nums[i] <= len - 1
		int l = 1;
		int r = len - 1;
		while(l < r) {
			int mid = (l + r) / 2;
			if(cnt(nums, mid) > mid) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}

	public static void main(String[] args) {
		new Leetcode287().findDuplicate(new int[]{1, 3, 4, 2, 2});
	}
}
