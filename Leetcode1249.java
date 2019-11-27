
import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/11/27
 *
 * @author dezhonger
 * @since 2019/11/27
 */
public class Leetcode1249 {

    public String minRemoveToMakeValid(String s) {
        StringBuilder res = new StringBuilder();

        List<Integer> leftBrackets = new ArrayList<>();
        boolean[] v = new boolean[s.length()];

        for (int i = 0; i < s.length(); i++) {
            if (Character.isLowerCase(s.charAt(i))) {
                v[i] = true;
                continue;
            }

            if (s.charAt(i) == '(') {
                leftBrackets.add(i);
            } else {
                if (leftBrackets.size() > 0) {
                    v[i] = true;
                    v[leftBrackets.get(leftBrackets.size() - 1)] = true;
                    leftBrackets.remove(leftBrackets.size() - 1);
                }
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (v[i]) res.append(s.charAt(i));
        }
        return res.toString();
    }

}
