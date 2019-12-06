
/**
 * Created by dezhonger on 2019/12/6
 */
public class Leetcode0927 {

    public int[] threeEqualParts(int[] A) {

        int s1 = 0, s2 = 0, s3 = 0;
        int e1 = 0, e2 = 0, e3 = A.length - 1;
        int[] error = new int[]{-1, -1};
        int ontCnt = 0;
        for (int i = 0; i < A.length; i++) if (A[i] == 1) ontCnt++;
        if (ontCnt % 3 != 0) return error;
        if (ontCnt == 0) {
            return new int[]{0, 2};
        }
        int tailZeroCnt = 0;
        for (int i = A.length - 1; i >= 0; i--, tailZeroCnt++) if (A[i] == 1) break;


        //calculate the start and end of the first number
        int firstOneCnt = 0;
        int firstZeroCnt = 0;
        for (int i = 0; i < A.length; i++) {
            if (firstOneCnt < ontCnt / 3) {
                if (A[i] == 1) firstOneCnt++;
            } else {

                if (A[i] == 1) return error;
                else firstZeroCnt++;
            }
            if (firstOneCnt == ontCnt / 3 && firstZeroCnt == tailZeroCnt) {
                e1 = i;
                s2 = i + 1;
                if (s2 >= A.length) return error;
                break;
            }

        }
        if (firstOneCnt != ontCnt / 3 || firstZeroCnt != tailZeroCnt) {
            return error;
        }

        //calculate the start and end of the second number
        int secondOneCnt = 0;
        int secondZeroCnt = 0;
        for (int i = s2; i < A.length; i++) {
            if (secondOneCnt < ontCnt / 3) {
                if (A[i] == 1) secondOneCnt++;
            } else {
                if (A[i] == 1) return error;
                else secondZeroCnt++;
            }
            if (secondOneCnt == ontCnt / 3 && secondZeroCnt == tailZeroCnt) {
                e2 = i;
                s3 = i + 1;
                if (s3 >= A.length) return error;
                break;
            }

        }
        if (secondOneCnt != ontCnt / 3 || secondZeroCnt != tailZeroCnt) {
            return error;
        }


        //check
        if (check(A, s1, e1, s2, e2) && check(A, s2, e2, s3, e3)) {
            return new int[]{e1, s3};
        } else {
            return error;
        }
    }

    private boolean check(int[] a, int s1, int e1, int s2, int e2) {
        return trimZero(a, s1, e1).equals(trimZero(a, s2, e2));
    }

    private String trimZero(int[] a, int l, int r) {
        int i = l;
        while (i <= r && a[i] == 0) i++;
        StringBuilder sb = new StringBuilder();
        while (i <= r) sb.append(a[i++]);
        return sb.toString();
    }

}
