
/**
 * Created by zhangweilong on 2019/07/30
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/07/30
 */

public class Leetcode0023 {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode root = new ListNode(Integer.MIN_VALUE);
        ListNode x = root;
        while (true) {
            int val = Integer.MAX_VALUE;
            int index = -1;
            for (int i = 0; i < lists.length; i++) {
                ListNode node = lists[i];
                if (node == null) continue;
                if (node.val < val) {
                    val = node.val;
                    index = i;
                }
            }
            if (index == -1) break;
            root.next = new ListNode(lists[index].val);
            root = root.next;
            lists[index] = lists[index].next;
        }
        return x.next;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}
