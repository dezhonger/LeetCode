package p1107.p20170222;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2017/2/22.
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */
public class Leetcode228 {
	public List<String> summaryRanges(int[] nums) {
		List<String> list = new ArrayList<>();
		if(nums == null || nums.length == 0) return list;
		int len = nums.length;
		if (len == 1) {
			list.add(nums[0] + "");
			return list;
		}
		int s = nums[0];
		int t = nums[0];
		for (int i = 1; i < len; i++) {
			int x = nums[i];
			if(x == nums[i-1] + 1) {
				t = x;
			} else {
				if(s != t) {
					list.add(s + "->" + t);
				} else {
					list.add(s + "");
				}
				s = t = x;
			}
		}
		if(s != t) {
			list.add(s + "->" + t);
		} else {
			list.add(s + "");
		}
		return list;
	}

	public static void main(String[] args) {
//		System.out.println(new Leetcode228().summaryRanges(new int[]{0,1,2,4,5,7}));
		System.out.println(new Leetcode228().summaryRanges(new int[]{-1}));
	}
}
