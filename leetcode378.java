//��һ������ÿ�к�ÿ�ж�������ģ��ҵ���k�������

//ά��һ��heap�����ȶ��У�(0, 0)��ӣ������ұߺ��±ߵ�����ѭ��k�μ��ɡ�

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