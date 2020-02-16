package com.netease.music.p20200216;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2020/2/16
 */
public class ProductOfNumbers {
    public static void main(String[] args) {
        ProductOfNumbers sol = new ProductOfNumbers();
        sol.add(0);
        sol.add(4);
        sol.add(0);
        sol.add(1);
        sol.add(4);
        sol.add(9);
        System.out.println(sol.getProduct(2));

        sol.add(0);
        sol.add(3);
        System.out.println(sol.getProduct(3));
        sol.add(3);
        System.out.println(sol.getProduct(2));
        sol.add(6);
        sol.add(1);
        System.out.println(sol.getProduct(5));
    }

    int n;
    List<Integer> list;
    List<Integer> zero;

    public ProductOfNumbers() {
        n = 0;
        list = new ArrayList<>();
        list.add(1);
        zero = new ArrayList<>();
    }

    public void add(int num) {
        n++;
        if (num == 0) {
            zero.add(n);
            list.add(0);
        } else {
            int last = list.get(n - 1);
            if (last == 0) list.add(num);
            else list.add(last * num);
        }
    }

    public int getProduct(int k) {
        int pre = n - k;
        for (int x : zero) {
            if (x > pre) return 0;
        }
        int la = list.get(n - k);
        if (la == 0) return list.get(n);
        else return list.get(n) / list.get(n - k);

    }
}
