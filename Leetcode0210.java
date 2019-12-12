package com.dezhonger.le;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by dezhonger on 2019/12/12
 *
 * @author dezhonger
 * @since 2019/12/12
 */
public class Leetcode0210 {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Leetcode0210().findOrder(2, new int[][]{
                {1, 0}
        })));
    }
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[][] matrix = new int[numCourses][numCourses]; // i -> j
        int[] indegree = new int[numCourses];

        for (int i = 0; i < prerequisites.length; i++) {
            int ready = prerequisites[i][0];
            int pre = prerequisites[i][1];
            if (matrix[pre][ready] == 0) //多重边
                indegree[ready]++;
            matrix[pre][ready] = 1;
        }

        int count = 0;
        int[] res = new int[numCourses];
        Queue<Integer> queue = new LinkedList();
        //所有入度为0的点
        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) queue.offer(i);
        }
        while (!queue.isEmpty()) {
            int course = queue.poll();
            res[count] = course;
            count++; //已经学完的课程
            for (int i = 0; i < numCourses; i++) {
                if (matrix[course][i] != 0) {
                    //编号为i的课程的先修课程都已经学完
                    if (--indegree[i] == 0)
                        queue.offer(i);
                }
            }
        }
        if (count == numCourses) {
            return res;
        } else {
            return new int[0];
        }

    }
//
//    public boolean canFinish(int numCourses, int[][] prerequisites) {
//        int[][] matrix = new int[numCourses][numCourses]; // i -> j
//        int[] indegree = new int[numCourses];
//
//        for (int i = 0; i < prerequisites.length; i++) {
//            int ready = prerequisites[i][0];
//            int pre = prerequisites[i][1];
//            if (matrix[ready][pre] == 0) //多重边
//                indegree[pre]++;
//            matrix[ready][pre] = 1;
//        }
//
//
//        int count = 0;
//        Queue<Integer> queue = new LinkedList();
//        //所有入度为0的点
//        for (int i = 0; i < indegree.length; i++) {
//            if (indegree[i] == 0) queue.offer(i);
//        }
//        while (!queue.isEmpty()) {
//            int course = queue.poll();
//            count++; //已经学完的课程
//            for (int i = 0; i < numCourses; i++) {
//                if (matrix[course][i] != 0) {
//                    //编号为i的课程的先修课程都已经学完
//                    if (--indegree[i] == 0)
//                        queue.offer(i);
//                }
//            }
//        }
//        return count == numCourses;
//    }
}
