package com.dezhonger.y2020.m01.d26;

/**
 * Created by dezhonger on 2020/01/26
 *
 * @author dezhonger
 * @since 2020/01/26
 * leetcode427
 */
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
public class Leetcode0427 {
    public Node construct(int[][] grid) {
        int N = grid.length;
        return construct(grid, 0, 0, N);
    }

    private Node construct(int[][] grid, int x, int y, int n) {
        if (n == 1) {
            Node node = new Node(grid[x][y] == 1, true, null, null, null, null);
            return node;
        }

        Node n1 = construct(grid, x, y, n / 2);
        Node n2 = construct(grid, x, y + n / 2, n / 2);
        Node n3 = construct(grid, x + n / 2, y, n / 2);
        Node n4 = construct(grid, x + n / 2, y + n / 2, n / 2);
        if (n1.isLeaf && n2.isLeaf && n3.isLeaf && n4.isLeaf
        && n1.val == n2.val && n2.val == n3.val && n3.val == n4.val) {
            return new Node(n1.val, true, null, null, null, null);
        } else {
            return new Node(false, false, n1, n2, n3, n4);
        }
    }
}
