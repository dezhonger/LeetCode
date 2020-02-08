package com.netease.music.p20200208;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2020/2/8
 */
public class Leetcode0787 {
    //https://www.luogu.com.cn/blog/ztyluogucpp/qian-tan-dijkstra

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        //建图
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] a : flights) graph.get(a[0]).add(new Edge(a[2], a[1]));

        //优先队列初始化, 按照边权从小到大排序
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o.dis));
        //最多k+1条边
        pq.add(new Node(src, 0, K + 1));

        while (!pq.isEmpty()) {
            Node poll = pq.poll();
            int dis = poll.dis;
            int point = poll.startPoint;
            int stop = poll.stop;
            //优先队列里维护着到达point的最小值
            if (point == dst) return dis;
            if (stop == 0) continue;
            //枚举从point所有的出边
            List<Edge> edges = graph.get(point);
            for (Edge edge : edges) {
                pq.add(new Node(edge.endPoint, dis + edge.dis, stop - 1));

            }
        }
        return -1;

    }

    class Edge {
        int dis;
        int endPoint;

        public Edge(int dis, int endPoint) {
            this.dis = dis;
            this.endPoint = endPoint;
        }
    }

    class Node {
        int startPoint;
        int dis;
        int stop;

        public Node(int startPoint, int dis, int stop) {
            this.startPoint = startPoint;
            this.dis = dis;
            this.stop = stop;
        }
    }
}
