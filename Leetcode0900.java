package com.netease.music.rep2.crontab.server.ds.dao.cache;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/07/19
 *
 * @author dezhonger
 * @since 2019/07/19
 */
public class Leetcode0900 {
    class RLEIterator {
        int index = 0;
        int use = 0;
        List<Node> list = new ArrayList<>();

        public RLEIterator(int[] A) {
            int len = A.length / 2;
            for (int i = 0; i < len; i++) {
                int c = A[2 * i];
                int v = A[2 * i + 1];
                if (c > 0) {
                    list.add(new Node(c, v));
                }
            }
        }

        public int next(int n) {
            for (int i = index; i < list.size(); i++) {
                Node node = list.get(i);
                if (node.cnt - use > n) {
                    use += n;
                    return node.val;
                } else if (node.cnt - use == n) {
                    use = 0;
                    index++;
                    return node.val;
                } else {
                    n = n - (node.cnt - use);
                    index++;
                    use = 0;
                }
            }
            return -1;
        }

        class Node {
            int cnt;
            int val;

            public Node(int cnt, int val) {
                this.cnt = cnt;
                this.val = val;
            }
        }
    }


/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */

}
