
/**
 * Created by dezhonger on 2019/6/22
 */
public class Leetcode0999 {

    private boolean check(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    public int numRookCaptures(char[][] board) {
        int r, x, y;
        x = y = r = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int[][] d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < d.length; i++) {
            int xx = x;
            int yy = y;
            while (check(xx, yy, board.length, board[0].length)) {
                if (board[xx][yy] == 'p') {
                    r++;
                    break;
                }
                if (board[xx][yy] == 'B') {
                    break;
                }
                xx += d[i][0];
                yy += d[i][1];

            }
        }
        return r;
    }
}
