package com.netease.music.p20200216;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2020/2/16
 */
public class Leetcode1354 {
    public static void main(String[] args) {
//        System.out.println(new Leetcode1354().isPossible(new int[]{1,1,1,1,11,16}));
//        System.out.println(new Leetcode1354().isPossible(new int[]{9, 3, 5}));
//        System.out.println(new Leetcode1354().isPossible(new int[]{1, 1, 2, 1}));
//        System.out.println(new Leetcode1354().isPossible(new int[]{8, 5}));
        System.out.println(new Leetcode1354().isPossible(new int[]{1,1_000_0000}));
        System.out.println(new Leetcode1354().isPossible2(new int[]{1,1_000_0000}));
    }

    public boolean isPossible(int[] target) {
        Arrays.sort(target);
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o2, o1));
        int len = target.length;

        long s = 0;
        for (int i = 0; i < len; i++){
            s += target[i];
            pq.add(target[i]);
        }

        while (!pq.isEmpty()) {
            int maxNum = pq.poll();
            if (maxNum == 1) return true;
            //下一个数
            if (maxNum - (s - maxNum) < 0) return false;
            //能减多少次
            int cishu = (int) (maxNum / (s - maxNum));
            long nxt = maxNum - cishu * (s - maxNum);
            s = s - maxNum + nxt;
            pq.add((int) nxt);
        }
        //cannot reach here
        return true;
    }

    public boolean isPossible2(int[] target) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int v : target){
            pq.add(-v);
        }
        long sum = 0;
        for(int v : target){
            sum += v;
        }
        int st = 0;
        while(true){
            st++;
            int cur = -pq.poll();
            if(cur == 1)break;
            if(cur-(sum-cur) > 0 && cur-(sum-cur) < cur){
                int an = (int)(cur-(sum-cur));
                sum -= cur - an;
                cur = an;
                pq.add(-cur);
            }else{
                return false;
            }
        }
        System.out.println(st);
        return true;
    }
}
