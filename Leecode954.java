
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangweilong on 2019/04/03
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/04/03
 */
public class Leecode954 {

    public boolean canReorderDoubled(int[] A) {
        int ma = 2000020;
        List<Integer> a = new ArrayList<>();
        int[] acnt = new int[ma];
        List<Integer> b = new ArrayList<>();
        List<Integer> c = new ArrayList<>();
        int[] ccnt = new int[ma];
        Arrays.sort(A);
        for (int x : A) {
            if (x < 0) {
                a.add(-x);
                acnt[-x]++;
            }
            else if (x == 0) b.add(x);
            else {
                c.add(x);
                ccnt[x]++;
            }
        }
        if (a.size() % 2 != 0 || b.size() % 2 != 0 || c.size() % 2 != 0) return false;
        for (int x : c) {
            if (ccnt[x] == 0) continue;
            if (ccnt[x << 1] == 0) return false;
            ccnt[x<<1]--;
            ccnt[x]--;
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            int x = a.get(i);
            if (acnt[x] == 0) continue;
            if (acnt[x<<1] == 0) return false;
            acnt[x<<1]--;
            acnt[x]--;
        }
        return true;
    }
}
