
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by dezhonger on 2019/07/19
 *
 * @author dezhonger
 * @since 2019/07/19
 */

public class Leetcode0901 {
    class StockSpanner {
        List<Integer> val = new ArrayList<>();
        int cnt = 0;
        Stack<Integer> stack = new Stack<>();

        public StockSpanner() {

        }

        public int next(int price) {
            val.add(price);
            while (!stack.isEmpty() && val.get(stack.peek()) <= price) {
                stack.pop();
            }
            int res = 0;
            if (stack.empty()) res = cnt + 1;
            else res = cnt - stack.peek();
            stack.push(cnt);
            cnt++;
            return res;

        }
    }
}
