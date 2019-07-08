

/**
 * Created by dezhonger on 2019/7/7
 */
public class Leetcode1111 {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int dep = 0;
        int maDep = 0;
        for (int i = 0; i < n; i++) {
            if (seq.charAt(i) == '(') dep++;
            else dep--;
            maDep = Math.max(maDep, dep);
        }
        int c = (maDep + 1) / 2;
        int a = 0, b = 0;
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            if (seq.charAt(i) == '(') {
                if (a == c) {
                    b++;
                    r[i] = 1;
                } else {
                    a++;
                    r[i] = 0;
                }
            } else {
                if (a != 0) {
                    a--;
                    r[i] = 0;
                } else {
                    b--;
                    r[i] = 1;
                }
            }
        }
        return r;
    }
}
