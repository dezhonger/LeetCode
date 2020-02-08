package com.netease.music.p20200208;

/**
 * Created by dezhonger on 2020/2/8
 */
public class MyCircularDeque {
    public static void main(String[] args) {
        MyCircularDeque m = new MyCircularDeque(3);
        m.insertLast(1);
        m.insertLast(2);
        m.insertFront(3);
        m.insertFront(4);
        System.out.println(m.getRear());
    }

    int[] a;
    int n;
    int k;
    int front, tail;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        this.k = k;
        this.n = 0;
        this.a = new int[k];
        front = k - 1;
        tail = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if (n == k) return false;
        a[front] = value;
        front = (front - 1 + k) % k;
        n++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if (n == k) return false;
        a[tail] = value;
        tail = (tail + 1) % k;
        n++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if (n == 0) return false;
        front = (front + 1) % k;
        n--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (n == 0) return false;
        tail = (tail - 1 + k) % k;
        n--;
        return true;
    }

    /** Get the front item from the deque. */
    public int getFront() {
        if (n == 0) return -1;
        return a[(front + 1) % k];
    }

    /** Get the last item from the deque. */
    public int getRear() {
        if (n == 0) return -1;
        return a[(tail - 1 + k) % k];
    }

    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return n == 0;
    }

    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return n == k;
    }
}
