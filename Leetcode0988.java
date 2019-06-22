
/**
 * Created by dezhonger on 2019/6/22
 */
public class Leetcode0988 {

    String r = "~";

    public String smallestFromLeaf(TreeNode root) {
        dfs(root, "");
        return r;
    }

    private void dfs(TreeNode root, String s) {
        if (root == null) return;
        s = (char) ('a' + root.val) + s;
        if (root.left == null && root.right == null) {
            if (s.compareTo(r) < 0) r = s;
        }
        dfs(root.left, s);
        dfs(root.right, s);
    }
}
