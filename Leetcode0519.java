package com.y2019.m12.d03;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/**
 * Created by zhangweilong on 2019/12/03
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/03
 */
public class Leetcode0519 {
    int size;
    int row, col;
    Map<Integer, Integer> map;
    Random random;

    public Leetcode0519(int n_rows, int n_cols) {
        size = n_cols * n_rows;
        map = new HashMap<>();
        row = n_rows;
        col = n_cols;
        random = new Random();
    }

    public int[] flip() {
        int x = random.nextInt(size);
        size--;
        int res = map.getOrDefault(x, x);
        map.put(x, map.getOrDefault(size, size));
        return new int[]{res / col, res % col};
    }

    public void reset() {
        size = row * col;
        map.clear();
    }
}
