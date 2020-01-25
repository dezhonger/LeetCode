package com.dezhonger.y2020.m01.d25;

import java.util.ArrayDeque;
import java.util.Iterator;
import java.util.Queue;

/**
 * Created by dezhonger on 2020/01/26
 *
 * @author dezhonger
 * @since 2020/01/26
 * leetcode284
 */
class PeekingIterator implements Iterator<Integer> {


    Iterator<Integer> it;
    Integer nxt;
    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        it = iterator;
        nxt = it.hasNext() ? it.next() : null;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return nxt;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer re = nxt;
        nxt = it.hasNext() ? it.next() : null;
        return re;
    }

    @Override
    public boolean hasNext() {
        return nxt != null;
    }
}
