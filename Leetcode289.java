package leetcode;

/**
 * Created by Dezhonger on 2017/2/22.
 * 用位运算，用第二位记录下一个状态
 */
public class Leetcode289 {

    public int cnt(int a, int b, int[][] x) {
        int m = x.length;
        int n = x[0].length;
        if(a < 0 || a >= m || b < 0 || b >= n) {
            return 0;
        }
        return x[a][b] & 1;
    }

    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        int[] nx = new int[]{1, 1, 1, 0, 0, -1, -1, -1};
        int[] ny = new int[]{1, 0, -1, 1, -1, 1, 0, -1};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int now = board[i][j] & 1;
                int lives = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + nx[k];
                    int y = j + ny[k];
                    lives += cnt(x, y, board);
                }
                if( (now == 1 && lives == 2) || lives == 3) {
                    board[i][j] |= 2; //重点
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
}
