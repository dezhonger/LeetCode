package com.dezhonger.y2020.m01.d15;

import java.util.Iterator;
import java.util.List;
import java.util.Stack;

/**
 * Created by dezhonger on 2020/01/15
 *
 * @author dezhonger
 * @since 2020/01/15
 * 341
 */
public class NestedIterator implements Iterator<Integer> {

    List<NestedInteger> nestedList;
    Stack<NestedInteger> stack = new Stack<>();
    public NestedIterator(List<NestedInteger> nestedList) {
        this.nestedList = nestedList;
        for (int i = nestedList.size() - 1; i >= 0; i--) stack.add(nestedList.get(i));
    }

    @Override
    public Integer next() {
        return stack.pop().getInteger();
    }

    @Override
    public boolean hasNext() {
        while (!stack.isEmpty()) {
            NestedInteger peek = stack.peek();
            if (peek.isInteger()) return true;
            stack.pop();
            List<NestedInteger> list = peek.getList();
            for (int i = list.size() - 1; i >= 0; i--) {
                stack.add(list.get(i));
            }
        }
        return false;
    }
}
