
import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/04/03
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/04/03
 */
public class Leetcode955 {
    public static void main(String[] args) {
        Leetcode955 code = new Leetcode955();
        System.out.println(code.minDeletionSize(new String[]{"ca","bb","ac"}));
        System.out.println(code.minDeletionSize(new String[]{"xc","yb","za"}));
        System.out.println(code.minDeletionSize(new String[]{"zyx","wvu","tsr"}));
        System.out.println(code.minDeletionSize(new String[]{"xga", "xfb", "yfa"}));
        System.out.println(code.minDeletionSize(new String[]{"doeeqiy","yabhbqe","twckqte"}));
    }

    public int minDeletionSize(String[] A) {
        int len = A[0].length();
        int r = 0;
        //标记下一轮不用再比较的字符串
        boolean[] need = new boolean[A.length];
        for (int i = 0; i < len; i++) {
            boolean f = true;
            boolean delete = false;
            List<Integer> l = new ArrayList<>();
            for (int j = 1; j < A.length; j++) {
                if (A[j].charAt(i) < A[j - 1].charAt(i)) {
                    if (need[j] == false) {
                        r++;
                        delete = true;
                        f = false;
                        break;
                    }
                } else if (A[j].charAt(i) == A[j - 1].charAt(i)) {
                    f = false;
                } else {
                    l.add(j);
                }
            }
            if (delete == false) {
                for (int kk : l) need[kk] = true;
            }
            if (f) return r;
        }
        return r;
    }
}
