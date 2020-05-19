package com.netease.music.leetcode;

import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Created by dezhonger on 2020/05/19
 */
public class Leetcode1452 {
//    [[],
//            [],
//            ["ovqdyfqmlpxapbjwtssm","qmsbphxzmnvflrwyvxlc","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"]]
    public static void main(String[] args) {
        new Leetcode1452().peopleIndexes(Lists.newArrayList(
                Lists.newArrayList("nxaqhyoprhlhvhyojanr","ovqdyfqmlpxapbjwtssm","qmsbphxzmnvflrwyvxlc","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty"),
                Lists.newArrayList("nxaqhyoprhlhvhyojanr","ovqdyfqmlpxapbjwtssm","udfuxjdxkxwqnqvgjjsp","yawoixzhsdkaaauramvg","zycidpyopumzgdpamnty")
        ));
        new Leetcode1452().peopleIndexes(Lists.newArrayList(
                Lists.newArrayList("leetcode", "google", "facebook"),
                Lists.newArrayList("google", "microsoft"),
                Lists.newArrayList("google", "facebook"),
                Lists.newArrayList("google"),
                Lists.newArrayList("amazon")
        ));
    }
    class Node {
        List<String> s;
        int index;
    }
    public List<Integer> peopleIndexes(List<List<String>> favoriteCompanies) {
        //每个按照字符串升序排列
        for (List<String> favoriteCompany : favoriteCompanies) {
            Collections.sort(favoriteCompany);
        }
        int len = favoriteCompanies.size();
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            Node node = new Node();
            node.s = favoriteCompanies.get(i);
            node.index = i;
            nodes.add(node);
        }
        //整理按照大小排序
        Collections.sort(nodes, Comparator.comparingInt(o -> o.s.size()));


        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            boolean f = false;
            for (int j = i + 1; j < len; j++) {
                if (check(nodes.get(i).s, nodes.get(j).s)) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                res.add(nodes.get(i).index);
            }
        }
        Collections.sort(res);
        return res;

    }

    //a是否是b的子集
    private boolean check(List<String> a, List<String> b) {
        if (a.size() >= b.size()) return false;
        for (String s : a) {
            if (!b.contains(s)) return false;
        }
        return true;
    }
}
