
import com.dezhonger.y2019.TreeNode;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/11/20
 *
 * @author dezhonger
 * @since 2019/11/20
 */
public class Leetcode1261 {

    Set<Integer> s = new HashSet<>();

    public Leetcode1261(TreeNode root) {
        if (root == null) return;
        root.val = 0;
        s.add(0);
        dfs(root);

    }

    private void dfs(TreeNode root) {
        if (root.left != null) {
            root.left.val = root.val * 2 + 1;
            s.add(root.left.val);
            dfs(root.left);
        }
        if (root.right != null) {
            root.right.val = root.val * 2 + 2;
            s.add(root.right.val);
            dfs(root.right);
        }

    }

    public boolean find(int target) {
        return s.contains(target);
    }
}
