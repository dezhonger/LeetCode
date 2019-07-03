
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/7/3
 */
public class Leetcode1104 {
    public static void main(String[] args) {
        new Leetcode1104().pathInZigZagTree(14);
    }
    public List<Integer> pathInZigZagTree(int label) {
        int len = 1 << 20;
        int[] nodes = new int[len];
        for (int i = 1; i < len; i++) {
            nodes[i] = i;
        }
        // 2 3 -> 2^1~2^1 - 1
        // 8 9 10 ... 15 2^3~2^3 - 1
        // 32 33 34 ... 63 2^5~2^5 - 1
        for (int i = 1; i < 20; i += 2) {
            int start = 1 << i;
            int end = (1 << (i + 1)) - 1;
            while (start < end) {
                int tmp = nodes[start];
                nodes[start] = nodes[end];
                nodes[end] = tmp;
                start++;
                end--;
            }
        }
        int ind = 0;
        for (int i = 1; i < len; i++) {
            if (nodes[i] == label) {
                ind = i;
                break;

            }
        }
        List<Integer> list = new ArrayList<>();
        list.add(nodes[ind]);
        while (ind > 1) {
            list.add(nodes[ind / 2]);
            ind /= 2;
        }
        Collections.reverse(list);
        return list;
    }

}
