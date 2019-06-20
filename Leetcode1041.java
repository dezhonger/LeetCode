
/**
 * Created by zhangweilong on 2019/06/20
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/06/20
 */
public class Leetcode1041 {

    public boolean isRobotBounded(String instructions) {
        int[][] d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int[] cur = {0, 0};
        int dir = 0;
        int t = 4;
        //最多4次会回到原位置和原方向
        while (t-- > 0) {
            for (char c : instructions.toCharArray()) {
                if (c == 'G') {
                    cur[0] += d[dir][0];
                    cur[1] += d[dir][1];
                } else if (c == 'R') dir = (dir + 1) % 4;
                else dir = (dir - 1 + 4) % 4;

            }
            if (cur[0] == 0 && cur[1] == 0 && dir == 0) {
                return true;
            }
        }
        return false;
    }
}
