package com.dezhonger.y2020.m02.d09;

/**
 * Created by dezhonger on 2020/02/09
 *
 * @author dezhonger
 * @since 2020/02/09
 */
public class MyLinkedList {

    int len;
    ListNode head;
    class ListNode {
        public ListNode nxt;
        public int val;

        public ListNode(int val) {
            this.val = val;
        }
    }

    /** Initialize your data structure here. */
    public MyLinkedList() {
        this.len = 0;
        this.head = new ListNode(-1);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index < 0 || index >= len) return -1;
        ListNode cur = head;
        for (int i = 0; i <= index; i++) {
            cur = cur.nxt;
        }
        return cur.val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        ListNode cur = new ListNode(val);
        cur.nxt = head.nxt;
        head.nxt = cur;
        len++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        ListNode cur = head;
        while (cur.nxt != null) cur = cur.nxt;
        cur.nxt = new ListNode(val);
        len++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index > len) return ;
        if (index == len) {
            addAtTail(val);
        } else if (index < 0) {
            addAtHead(val);
        } else {
            //第一个节点
            ListNode cur = head.nxt;
            ListNode pre = head;

            for (int i = 0; i <= index - 1; i++) {
                pre = cur;
                cur = cur.nxt;
            }
            ListNode t = new ListNode(val);
            t.nxt = pre.nxt;
            pre.nxt = t;
            len++;
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return ;
        //第一个节点
        ListNode cur = head.nxt;
        ListNode pre = head;

        for (int i = 0; i <= index - 1; i++) {
            pre = cur;
            cur = cur.nxt;
        }
        pre.nxt = cur.nxt;
        len--;
    }
}
