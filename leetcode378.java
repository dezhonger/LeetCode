//给一个矩阵，每行和每列都是增序的，找到第k大的数。

//维护一个heap或优先队列，(0, 0)入队，加入右边和下边的数，循环k次即可。

public class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int m = matrix.length;
        if (m == 0)
            return 0;
        int n = matrix[0].length;
        int cnt = 0;
        boolean[][] used = new boolean[m][n];
        PriorityQueue<Node> heap = new PriorityQueue<Node>();
        heap.add(new Node(0, 0, matrix[0][0]));
        used[0][0] = true;
        Node node = null;
        int[] xoff = {0, 1};
        int[] yoff = {1, 0};
        while (cnt < k) {
            node = heap.poll();
            int x = node.x;
            int y = node.y;
            for (int i = 0; i < 2; i++) {
                int xx = x + xoff[i];
                int yy = y + yoff[i];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && !used[xx][yy]) {
                    used[xx][yy] = true;
                    heap.add(new Node(xx, yy, matrix[xx][yy]));
                }
            }
            cnt++;
        }

        return node.val;
    }
}


class Node implements Comparable<Node> {
    int x, y;
    int val;

    public Node(int x, int y, int val) {
        this.x = x;
        this.y = y;
        this.val = val;
    }
    public int compareTo(Node o) {
        return val - o.val;
    }
}