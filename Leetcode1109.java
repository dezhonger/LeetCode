
/**
 * Created by dezhonger on 2019/7/7
 */
public class Leetcode1109 {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] result = new int[n + 2];
        for (int i = 0; i < bookings.length; i++) {
            int l = bookings[i][0];
            int r = bookings[i][1];
            int add = bookings[i][2];
            result[l] += add;
            result[r + 1] -= add;
        }
        for (int i = 1; i <= n; i++) {
            result[i] += result[i - 1];
        }
        int[] r = new int[n];
        System.arraycopy(result, 1, r, 0, n);
        return r;
    }
}
