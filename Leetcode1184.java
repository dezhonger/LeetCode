
/**
 * Created by zhangweilong on 2019/09/09
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/09/09
 */
public class Leetcode1184 {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int s = 0;
        for (int x : distance) s += x;
        int r = 0;
        for (int i = Math.min(start, destination); i < Math.max(start, destination); i++) r += distance[i];
        return Math.min(r, s - r);
    }
}
