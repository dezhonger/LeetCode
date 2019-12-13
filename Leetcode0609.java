package com.dezhonger.le;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by dezhonger on 2019/12/13
 *
 * @author dezhonger
 * @since 2019/12/13
 */
public class Leetcode0609 {

    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : paths) {
            String[] line = s.split(" ");
            if (line.length <= 1) {
                continue;
            }
            String dir = line[0];
            for (int j = 1; j < line.length; j++) {
                String fileDesc = line[j];
                int index = fileDesc.indexOf('(');
                String filename = fileDesc.substring(0, index);
                String content = fileDesc.substring(index + 1, fileDesc.length() - 1);
                put(content, dir + "/" + filename, map);
            }
        }
        List<List<String>> res = new ArrayList<>();
        map.forEach((k, v) -> {
            if (v.size() > 1)
                res.add(v);
        });
        return res;
    }

    void put(String content, String dir, Map<String, List<String>> map) {
        List<String> list = map.get(content);
        if (list == null) {
            list = new ArrayList<>();
            list.add(dir);
            map.put(content, list);
        } else {
            list.add(dir);
        }

    }
}
