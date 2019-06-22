

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Objects;
import java.util.Set;

/**
 * Created by dezhonger on 2019/4/1
 */
public class Leetcode1001 {

    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        Map<Integer, Integer> mx = new HashMap<>();
        Map<Integer, Integer> my = new HashMap<>();
        Map<Integer, Integer> ms = new HashMap<>();
        Map<Integer, Integer> md = new HashMap<>();
        Set<Node> nodes = new HashSet<>();
        for (int i = 0; i < lamps.length; i++) {
            int x = lamps[i][0];
            int y = lamps[i][1];
            mx.put(x, mx.getOrDefault(x, 0) + 1);
            my.put(y, my.getOrDefault(y, 0) + 1);
            ms.put(x + y, ms.getOrDefault(x + y, 0) + 1);
            md.put(x - y, md.getOrDefault(x - y, 0) + 1);
            Node node = new Node(x, y);
            nodes.add(node);
        }

        int[] r = new int[queries.length];
        int[] dx = new int[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int[] dy = new int[]{-1, 0, 1, -1, 0, 1, -1, 0, 1};
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (mx.getOrDefault(x, 0) > 0 || my.getOrDefault(y, 0) > 0 || ms.getOrDefault(x + y, 0) > 0 || md.getOrDefault(x - y, 0) > 0)
                r[i] = 1;
            else r[i] = 0;
            for (int k = 0; k < 9; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (nodes.contains(new Node(xx, yy))) {
                    nodes.remove(new Node(xx, yy));
                    mx.put(xx, mx.getOrDefault(xx, 0) - 1);
                    my.put(yy, my.getOrDefault(yy, 0) - 1);
                    ms.put(xx + yy, ms.getOrDefault(xx + yy, 0) - 1);
                    md.put(xx - yy, md.getOrDefault(xx - yy, 0) - 1);
                }
            }
        }
        return r;
    }

    class Node {
        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Node node = (Node) o;
            return x == node.x &&
                    y == node.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        int x, y;
    }
}
