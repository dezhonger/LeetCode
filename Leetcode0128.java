

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2017/2/17.
 * 如果一段连续的序列[L, R]的长度为x,那么map.get(L) = map.get(R) = x
 */
public class Leetcode0128 {
	//[100,4,200,1,3,2] return 4
	public int longestConsecutive(int[] nums) {
		int ans = 0;
		Map<Integer, Integer> map = new HashMap<>();
		for(int a : nums) {
			if(!map.containsKey(a)) {
				int l = a - 1;
				int r = a + 1;
				int llen = map.containsKey(l) ? map.get(l) : 0;
				int rlen = map.containsKey(r) ? map.get(r) : 0;
				int newlen = llen + rlen + 1;
				ans = Math.max(ans, newlen);
				map.put(a, newlen);
				map.put(a - llen, newlen);
				map.put(a + rlen, newlen);
			}
		}
		return ans;
	}
}
