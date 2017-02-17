package p1107.p20170217;

import java.util.*;

/**
 * Created by dezhonger on 2017/2/17.
 */


public class Leetcode508 {

	Map<Integer, Integer> map = new HashMap<>();

	public int findSum(TreeNode root) {
		if(root == null) return 0;
		int sum = root.val + findSum(root.left) + findSum(root.right);
		if(!map.containsKey(sum)) {
			map.put(sum, 1);
		} else {
			map.put(sum, map.get(sum) + 1);
		}
		return sum;
	}

	public int[] findFrequentTreeSum(TreeNode root) {
		findSum(root);
		List<Integer> list = new ArrayList<>();
		int maxCnt = 0;
		Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();
		while (it.hasNext()) {
			Map.Entry<Integer, Integer> entry = it.next();
			maxCnt = Math.max(maxCnt, entry.getValue());
		}
		it = map.entrySet().iterator();
		while (it.hasNext()) {
			Map.Entry<Integer, Integer> entry = it.next();
			if(entry.getValue() == maxCnt) {
				list.add(entry.getKey());
			}
		}
		int[] ans = new int[list.size()];
		for(int i = 0; i < list.size(); i++) {
			ans[i] = list.get(i);
		}
		return ans;
	}

}
