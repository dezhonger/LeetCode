
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/6/22
 */
public class Leetcode0987 {

    List<Node> list = new ArrayList<>();
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        dfs(root, 0, 0);
        Collections.sort(list);
        List<List<Integer>> r = new ArrayList<>();
        int last = Integer.MIN_VALUE;
        List<Integer> tmp = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            Node node = list.get(i);
            if (node.x == last) tmp.add(node.val);
            else {
                if (tmp.size() != 0) r.add(tmp);
                tmp = new ArrayList<>();
                tmp.add(node.val);
                last = node.x;
            }
        }
        r.add(tmp);
        return r;
    }

    private void dfs(TreeNode root, int x, int y) {
        if (root == null) return;
        list.add(new Node(x, y, root.val));
        dfs(root.left, x - 1, y - 1);
        dfs(root.right, x + 1, y - 1);
    }

    class Node implements Comparable<Node>{

        Node(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
        int x, y, val;

        @Override
        public int compareTo(Node o) {
            if (x != o.x) return Integer.compare(x, o.x);
            if (y != o.y) return Integer.compare(o.y, y);
            return Integer.compare(val, o.val);
        }

    }
}
