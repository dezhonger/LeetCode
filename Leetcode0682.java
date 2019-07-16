
import java.util.LinkedList;
import java.util.List;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0682 {
    public int calPoints(String[] ops) {
        List<Integer> list = new LinkedList<>();
        for (String op : ops) {
            if (op.equals("C")) {
                list.remove(list.size() - 1);
            } else if (op.equals("+")) {
                list.add(list.get(list.size() - 1) + list.get(list.size() - 2));
            } else if (op.equals("D")) {
                list.add(list.get(list.size() - 1) * 2);
            } else {
                list.add(Integer.valueOf(op));
            }
        }
        return list.stream().mapToInt(Integer::intValue).sum();
    }
}
