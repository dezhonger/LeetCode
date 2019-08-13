/**
 * Created by zhangweilong on 2019/08/13
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/13
 */
public class Leetcode1154 {

    public int dayOfYear(String date) {
        String[] split = date.split("-");
        int y = Integer.valueOf(split[0]);
        int m = Integer.valueOf(split[1]);
        int d = Integer.valueOf(split[2]);
        int[] md = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (y % 400 == 0 || ( y % 100 != 0 && y % 4 == 0)) md[1]++;
        int r = 0;
        for (int i = 0; i < m - 1; i++) r += md[i];
        return r + d;
    }
}
