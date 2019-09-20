package p1107.p20170217;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2017/2/17.
 */
public class Leetcode515 {

	int maxDepth = 0;
	public void findDepth(TreeNode root, int dep) {
		if(root != null) {
			maxDepth = Math.max(maxDepth, dep);
			findDepth(root.left, dep + 1);
			findDepth(root.right, dep + 1);
		}
	}

	public void solve(int[] ans, TreeNode root, int dep) {
		if(root != null) {
			int val = root.val;
			ans[dep] = Math.max(ans[dep], val);
			solve(ans, root.left, dep + 1);
			solve(ans, root.right, dep + 1);
		}
	}

	public List<Integer> largestValues(TreeNode root) {
		findDepth(root, 1);
		List<Integer> list = new ArrayList<>();
		if(maxDepth == 0) return list;

		int[] ans = new int[maxDepth + 1];
		for(int i = 1; i <= maxDepth; i++) {
			ans[i] = Integer.MIN_VALUE;
		}
		solve(ans, root, 1);
		for(int i = 1; i <= maxDepth; i++) {
			list.add(ans[i]);
		}
		return list;
	}
}
