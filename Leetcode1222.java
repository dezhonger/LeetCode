package com.y2019.m12.d25;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Created by zhangweilong on 2019/12/25
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/25
 */
public class Leetcode1222 {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        int n = 8;
        List<List<Integer>> res = new ArrayList<>();
        boolean[][] v = new boolean[8][8];
        for (int[] pos : queens) v[pos[0]][pos[1]] = true;
        int x = king[0];
        int y = king[1];
        int _x, _y;
        boolean find;

        _x = x;
        _y = y;
        find = false;

        while (!find && _x >= 0) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _x--;
        }

        _x = x;
        _y = y;
        find = false;

        while (!find && _x < n) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _x++;
        }

        _x = x;
        _y = y;
        find = false;

        while (!find && _y >= 0) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _y--;
        }

        _x = x;
        _y = y;
        find = false;

        while (!find && _y < n) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _y++;
        }


        _x = x;
        _y = y;
        find = false;

        while (!find && _x >= 0 && _y >= 0) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _x--;
            _y--;
        }

        _x = x;
        _y = y;
        find = false;
        while (!find && _x < n && _y < n) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _x++;
            _y++;
        }


        _x = x;
        _y = y;
        find = false;

        while (!find && _x >= 0 && _y < n) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _x--;
            _y++;
        }

        _x = x;
        _y = y;
        find = false;
        while (!find && _x < n && _y >= 0) {
            if (v[_x][_y]) {
                res.add(Stream.of(_x, _y).collect(Collectors.toList()));
                find = true;
            }
            _x++;
            _y--;
        }
        return res;
    }
}
