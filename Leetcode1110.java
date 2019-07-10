
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by dezhonger on 2019/7/10
 */
public class Leetcode1110 {

    List<TreeNode> list = new ArrayList<>();

    Set<Integer> vals = new HashSet<>();

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Arrays.stream(to_delete).forEach(vals::add);
        dfs(root);
        if (!vals.contains(root.val)) list.add(root);
        return list;
    }

    private void dfs(TreeNode root) {
        if (root == null) return;
        dfs(root.left);
        dfs(root.right);
        if (vals.contains(root.val)) {
            if (root.left != null && !vals.contains(root.left.val)) {
                list.add(root.left);
                root.left = null;
            }

            if (root.right != null && !vals.contains(root.right.val)) {
                list.add(root.right);
                root.right = null;
            }
        } else {
            if (root.left != null && vals.contains(root.left.val)) root.left = null;
            if (root.right != null && vals.contains(root.right.val)) root.right = null;
        }
    }
}
