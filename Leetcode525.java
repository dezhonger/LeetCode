package p1107.p20170222;


import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2017/2/22.
 * 给了一个01数组，找出最长的连续子数组1和0的个数相同
 * 等价为：把0变为-1，找出最长子数组和为0
 * 做法：记录前缀和即可。
 */
public class Leetcode525 {
	public int findMaxLength(int[] nums) {
		int len = nums.length;
		for (int i = 0; i < len; i++) {
			if (nums[i] == 0) {
				nums[i] = -1;
			}
		}
		Map<Integer, Integer> map = new HashMap<>();
		map.put(0, -1);
		int subsum = 0;
		int ans = 0;
		for (int i = 0; i < len; i++) {
			subsum += nums[i];
			if (map.containsKey(subsum)) {
				ans = Math.max(ans, i - map.get(subsum));
			} else {
				map.put(subsum, i);
			}

		}

		return ans;
	}
}
