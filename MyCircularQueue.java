package com.netease.music.p20200208;

/**
 * Created by dezhonger on 2020/2/8
 */
public class MyCircularQueue {
    public static void main(String[] args) {
        MyCircularQueue myCircularQueue = new MyCircularQueue(8);
        myCircularQueue.enQueue(3);
        myCircularQueue.enQueue(9);
        myCircularQueue.enQueue(5);
        myCircularQueue.enQueue(0);
        System.out.println(myCircularQueue.deQueue());
        System.out.println(myCircularQueue.deQueue());
        System.out.println(myCircularQueue.isEmpty());
        System.out.println(myCircularQueue.isEmpty());
        System.out.println(myCircularQueue.Rear());
    }

    int[] a;
    int front;
    int tail;
    int k;
    int n;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        this.k = k;
        this.a = new int[k];
        this.n = 0;
        this.front = 0;
        this.tail = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if (n == k) return false;
        n++;
        a[tail] = value;
        tail = (tail + 1) % k;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (n == 0) return false;
        front = (front + 1) % k;
        n--;
        return true;
    }

    /** Get the front item from the queue. */
    public int Front() {
        if (n == 0) return -1;
        return a[front];
    }

    /** Get the last item from the queue. */
    public int Rear() {
        if (n == 0) return -1;
        return a[(tail - 1 + k) % k];
    }

    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return n == 0;
    }

    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return n == k;
    }
}
