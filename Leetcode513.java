package p1107.p20170217;


/**
 * Created by dezhonger on 2017/2/17.
 * 找到最后一行最左边的值。
 * 先求出最大的深度
 * 然后递归找到第一个值即可
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Leetcode513 {

	int maxDepth = 0;
	int ans = 0;
	boolean find = false;
	public void findDepth(TreeNode root, int dep) {
		if(root != null) {
			maxDepth = Math.max(maxDepth, dep);
			findDepth(root.left, dep + 1);
			findDepth(root.right, dep + 1);
		}
	}

	public void findAns(TreeNode root, int dep) {
		if(root == null) return ;
		if(dep == maxDepth) {
			if(!find) {
				ans = root.val;
				find = true;
			} else {
				return ;
			}
		} else {
			findAns(root.left, dep + 1);
			findAns(root.right, dep + 1);
		}
	}

	public int findBottomLeftValue(TreeNode root) {
		findDepth(root, 1);
		findAns(root, 1);
		return ans;
	}
}
