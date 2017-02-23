/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Leetcode337 {
    public int rob(TreeNode root) {
        int[] ans = dfs(root);
        return Math.max(ans[0], ans[1]);
    }
    public int[] dfs(TreeNode x) {
        if(x == null) return new int[2];
        int[] l = dfs(x.left);
        int[] r = dfs(x.right);
        int[] ans = new int[2];
        ans[0] = x.val + l[1] + r[1];//choose node x
        ans[1] = Math.max(l[0], l[1]) + Math.max(r[0], r[1]);
        return ans;
    }
}
