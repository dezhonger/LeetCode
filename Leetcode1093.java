
/**
 * Created by dezhonger on 2019/6/23
 */
public class Leetcode1093 {


    private int len;

    private double g1(int[] count) {
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0) return i;
        }
        return -1;
    }

    private double g2(int[] count) {
        for (int i = count.length - 1; i >= 0; i--) {
            if (count[i] > 0) return i;
        }
        return -1;
    }

    private double g3(int[] count) {
        double s = 0;
        for (int i = 0; i < count.length; i++) {
            s += i * count[i];
        }
        return s / len;
    }

    private double g4(int[] count) {
        if (len % 2 == 1) {
            int mid = len / 2 + 1;
            int c = 0;
            for (int i = 0; i < count.length; i++) {
                c += count[i];
                if (c >= mid) return i;
            }
        } else {
            int mid1 = len / 2;
            int mid2 = mid1 + 1;
            int c = 0;
            int s = 0;
            boolean f1 = false;
            boolean f2 = false;
            for (int i = 0; i < count.length; i++) {
                c += count[i];
                if (c >= mid1 && !f1) {
                    s += i;
                    f1 = true;
                }
                if (c >= mid2 && !f2) {
                    s += i;
                    f2 = true;
                }
                if (f1 && f2) {
                    return 1.0 * s / 2;
                }
            }

        }
        return -1;
    }

    private double g5(int[] count) {
        int ma = Integer.MIN_VALUE;
        int r = -1;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > ma) {
                ma = count[i];
                r = i;
            }
        }
        return r;
    }


    public double[] sampleStats(int[] count) {
        double[] r = new double[5];
        for (int i = 0; i < count.length; i++) {
            len += count[i];
        }
        r[0] = g1(count);
        r[1] = g2(count);
        r[2] = g3(count);
        r[3] = g4(count);
        r[4] = g5(count);
        return r;
    }
}
