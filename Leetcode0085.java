import java.util.Stack;

/**
 * Created by dezhonger on 2020/2/23
 */
public class Leetcode0085 {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;

        int m = matrix.length;
        int n = matrix[0].length;
        int[][] s = new int[m + 1][n + 1];

        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int cur = matrix[i - 1][j - 1] == '1' ? 1 : 0;
                s[i][j] = cur == 0 ? 0 : s[i - 1][j] + cur;
            }
            res = Math.max(res, cal(s[i]));
        }
        return res;
    }

    public int cal(int[] high) {
        int len = high.length;
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < len; i++) {
            int cur = high[i];
            if (stack.isEmpty()) {
                stack.add(i);
            } else {
                while (!stack.isEmpty() && cur <= high[stack.peek()]) {
                    int h = high[stack.pop()];
                    int right = i - 1;
                    int left = stack.isEmpty() ? 0 : stack.peek() + 1;
                    int tmpRes = (right - left + 1) * h;
                    res = Math.max(res, tmpRes);
                }
                stack.add(i);
            }
        }

        while (!stack.isEmpty()) {
            int right = stack.peek();
            int h = high[stack.pop()];
            int left = stack.isEmpty() ? 0 : stack.peek() + 1;
            int tmpRes = (right - left + 1) * h;
            res = Math.max(res, tmpRes);
        }
        return res;
    }
}
