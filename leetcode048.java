//一个数旋转四次回到原地，求出这几个位置，循环交换一下，空间复杂度O(1)
public class Solution {
    public void rotate(int[][] matrix) {
        int m = matrix.length;
        if (m == 0) return;
        int mid = m / 2;
        for (int i = 0; i < mid; i++) {
            for (int j = i; j < m - i - 1; j++) {
                int[] nextx = new int[3];
                int[] nexty = new int[3];
                nextx[0] = j;
                nexty[0] = m - i - 1;
                nextx[1] = nexty[0];
                nexty[1] = m - 1 - nextx[0];
                nextx[2] = m - 1 - j;
                nexty[2] = i;
                int t = matrix[i][j];
                matrix[i][j] = matrix[nextx[2]][nexty[2]];
                matrix[nextx[2]][nexty[2]] = matrix[nextx[1]][nexty[1]];
                matrix[nextx[1]][nexty[1]] = matrix[nextx[0]][nexty[0]];
                matrix[nextx[0]][nexty[0]] = t;
            }
        }

    }
}


