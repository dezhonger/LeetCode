
/**
 * Created by dezhonger on 2019/6/22
 */
public class Leetcode0985 {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int even = 0;
        for (int x : A) {
            if (x % 2 == 0) even += x;
        }
        int[] r = new int[queries.length];
        for (int i = 0; i < queries.length;i ++) {
            int val = queries[i][0];
            int index = queries[i][1];
            if (A[index] % 2 == 0) {
                even -= A[index];
            }
            A[index] += val;
            if (A[index] % 2 == 0) {
                even += A[index];
            }
            r[i] = even;
        }
        return r;
    }
}
