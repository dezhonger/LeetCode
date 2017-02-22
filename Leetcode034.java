package p1107.p20170222;

/**
 * Created by dezhonger on 2017/2/22.
 * 选择出target的区域。
 * 做法：
 * 先二分找出是否存在。
 * 存在的话分别二分找出两个边界
 * O(3NlogN)
 */
public class Leetcode034 {

	public static void main(String[] args) {
		int[] a = new Leetcode034().searchRange(new int[]{5,7,7,8,8,10}, 8);
		System.out.println(a[0] + " " + a[1]);
	}


	public boolean find(int[] nums, int target) {
		int len = nums.length;
		int l = 0;
		int r = len - 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			int x = nums[mid];
			if(x == target) return true;
			if(x < target) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return false;
	}

	public int findLeft(int[] nums, int target) {
		int len = nums.length;
		int l = 0;
		int r = len - 1;
		while(l < r) {
			//这里注意。。否则题目会死循环，选择靠左的那个
			int mid = (l + r) / 2;
			int x = nums[mid];
			if(x > target) {
				r = mid - 1;
			} else if(x < target){
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}

	public int findRight(int[] nums, int target) {
		int len = nums.length;
		int l = 0;
		int r = len - 1;
		while(l < r) {
			//这里注意。。否则题目会死循环，选择靠右的那个
			int mid = (l + r + 1) / 2;
			int x = nums[mid];
			if(x < target) {
				l = mid + 1;
			} else if(x > target){
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		return l;
	}


	public int[] searchRange(int[] nums, int target) {
		boolean have = find(nums, target);
		if(!have) {
			return new int[]{-1, -1};
		}
		return new int[]{findLeft(nums, target), findRight(nums, target)};
	}
}
