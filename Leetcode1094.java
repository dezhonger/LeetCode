
import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by dezhonger on 2019/6/23
 */
public class Leetcode1094 {


    public boolean carPooling(int[][] trips, int capacity) {
        Arrays.sort(trips, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] != o2[1]) return Integer.compare(o1[1], o2[1]);
                return Integer.compare(o1[2], o2[2]);
            }
        });

        int c = 0;
        boolean[] f = new boolean[trips.length];
        for (int i = 0; i < trips.length; i++) {
            int shang = trips[i][1];
            for (int j = 0; j < i; j++) {
                if (trips[j][2] <= shang && !f[j]) {
                    c -= trips[j][0];
                    f[j] = true;
                }
            }
            if (c + trips[i][0] > capacity) return false;
            c += trips[i][0];
        }

        return true;
    }
}
