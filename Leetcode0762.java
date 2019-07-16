
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0762 {

    public int countPrimeSetBits(int L, int R) {
        Set<Integer> set = new HashSet<>(Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19));
        int r = 0;
        for (int i = L; i <= R; i++) {
            if (set.contains(Integer.bitCount(i))) r++;
        }
        return r;
    }

}
