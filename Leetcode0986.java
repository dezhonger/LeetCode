
import java.util.LinkedList;
import java.util.List;

/**
 * Created by dezhonger on 2019/6/22
 *
 * O(N^2)
 */
public class Leetcode0986 {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> list = new LinkedList<>();
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                if (A[i][0] > B[j][1]) continue;
                if (A[i][1] < B[j][0]) break;
                int[] tmp = new int[2];
                tmp[0] = Math.max(A[i][0], B[j][0]);
                tmp[1] = Math.min(A[i][1], B[j][1]);
                list.add(tmp);
            }
        }
        int[][] r = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            r[i][0] = list.get(i)[0];
            r[i][1] = list.get(i)[1];
        }
        return r;
    }
}
