
/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0686 {
    public int repeatedStringMatch(String A, String B) {
        int len1 = A.length();
        int len2 = B.length();
        String A2 = A + A;
        if (len1 >= len2) {
            if (A.contains(B)) return 1;
            else if (A2.contains(B)) return 2;
            return -1;

        } else  {
            int c = (len2 + len1 - 1) / len1;
            StringBuilder AA = new StringBuilder();
            for (int i = 0; i < c; i++) AA.append(A);
            if (AA.toString().contains(B)) return c;
            else if ((AA.toString() + A).contains(B)) return c + 1;
            else return -1;
        }
    }
}
