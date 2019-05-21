
/**
 * Created by dezhonger on 2019/5/21
 */
public class Leetcode0949 {

    private boolean check(int[] A, int... a) {
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (a[i] == a[j]) return false;
            }
        }
        int hou = A[a[0]] * 10 + A[a[1]];
        int min = A[a[2]] * 10 + A[a[3]];

        return hou <= 23 && min <= 59;
    }


    public String largestTimeFromDigits(int[] A) {
        int len = A.length;
        int ma = -1;
        for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
        for (int k = 0; k < len; k++)
        for (int l = 0; l < len; l++) {
            if (check(A, i, j, k, l)) {
                int cur = A[l] + 10 * A[k] + 100 * A[j] + 1000 * A[i];
                ma = Math.max(cur, ma);
            }
        }
        if (ma == -1) return "";
        else {
            String x = ma + "";
            int le = x.length();
            for (int i = 0; i < 4 - le; i++)  x = "0" + x;
            return x.substring(0, 2) + ":" + x.substring(2);
        }

    }
}
