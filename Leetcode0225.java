package p1107.p20170214;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by dezhonger on 2017/2/14.
 * 存的时候逆序存储，即可
 */
public class Leetcode225 {

	Queue<Integer> q = null;

	/** Initialize your data structure here. */
	public Leetcode225() {
		q = new LinkedList<Integer>();
	}

	/** Push element x onto stack. */
	public void push(int x) {
		q.add(x);
		int size = q.size();
		while(size-- > 1) {
			q.add(q.poll());//将最早进栈的放到最后
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	public int pop() {
		return q.poll();
	}

	/** Get the top element. */
	public int top() {
		return q.peek();
	}

	/** Returns whether the stack is empty. */
	public boolean empty() {
		return q.isEmpty();
	}
}
