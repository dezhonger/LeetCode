
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/11/27
 *
 * @author dezhonger
 * @since 2019/11/27
 */
public class Leetcode0842 {

    public List<Integer> splitIntoFibonacci(String S) {
        if (S == null || S.length() == 0) return Collections.emptyList();
        for (int i = 1; i < Math.min(S.length(), 10); i++) {
            for (int j = i + 1; j < Math.min(S.length(), i + 11); j++) {
                String firstS = S.substring(0, i);
                String secondS = S.substring(i, j);

                if (!checkInt(firstS)) continue;
                if (!checkInt(secondS)) continue;
                int first = (int) Long.parseLong(firstS);
                int second = (int) Long.parseLong(secondS);
                boolean f = true;
                int index = j;
                List<Integer> tmp = new ArrayList<>();
                tmp.add(first);
                tmp.add(second);
                while (true) {
                    int next = add(first, second);
                    if (next == -1) {
                        f = false;
                        break;
                    } else {
                        int k = length(next);
                        if (index + k > S.length()) {
                            f = false;
                            break;
                        }
                        String nextS = S.substring(index, index + k);
                        if (!checkInt(nextS)) {
                            f = false;
                            break;
                        }
                        int nextf = Integer.parseInt(nextS);
                        if (nextf != next) {
                            f = false;
                            break;
                        } else {
                            tmp.add(next);
                            first = second;
                            second = nextf;
                            index = index + k;
                            if (index == S.length()) {
                                break;

                            }
                        }
                    }
                }
                if (f) {
                    return tmp;
                }
            }
        }
        return Collections.emptyList();
    }

    private int length(int a) {
        if (a == 0) return 1;
        int r = 0;
        while (a > 0) {
            a /= 10;
            r++;
        }
        return r;
    }


    private boolean checkInt(String s) {
        if (s.length() == 1) return true;
        if (s.charAt(0) == '0') return false;
        long l = Long.parseLong(s);
        return l <= Integer.MAX_VALUE;
    }

    private int add(int s1, int s2) {
        long l = 0L + s1 + s2;
        if (l <= Integer.MAX_VALUE) return (int) l;
        return -1;
    }

}
