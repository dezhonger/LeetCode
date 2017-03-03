package p1107.p20170303;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2017/3/3.
 * 一个BST求两个数的差的最小值。
 * hint:中序遍历得到升序序列
 */

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

public class Leetcode530 {
	List<Integer> list = new ArrayList<>();

	public void inOrder(TreeNode root) {
		if(root == null) {
			return ;
		}
		if(root.left != null) {
			inOrder(root.left);
		}
		list.add(root.val);
		if(root.right != null) {
			inOrder(root.right);
		}
	}
	public int getMinimumDifference(TreeNode root) {
		inOrder(root);
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < list.size() - 1; i++) {
			ans = Math.min(ans, Math.abs(list.get(i) - list.get(i + 1)));
		}
		return ans;
	}
}
