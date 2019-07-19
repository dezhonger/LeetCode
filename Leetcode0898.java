
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/07/19
 *
 * @author dezhonger
 * @since 2019/07/19
 */
public class Leetcode0898 {
    public static void main(String[] args) {
        int i = new Leetcode0898().subarrayBitwiseORs(new int[]{1, 2, 4});
        System.out.println(i);
    }
    public int subarrayBitwiseORs(int[] A) {
        //结果
        Set<Integer> res = new HashSet<>();
        //每次以上个数为最后一个数的子数组所得到的或值的集合
        Set<Integer> set = new HashSet<>();
        for (int x : A) {
            Set<Integer> tmp = new HashSet<>();
            tmp.add(x);
            set.stream().forEach(e -> tmp.add(e | x));
            res.addAll(tmp);
            set.clear();
            set.addAll(tmp);
        }
        return res.size();
    }
}
