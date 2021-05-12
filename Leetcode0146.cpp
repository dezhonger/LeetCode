#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0146.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-12 23:23:33
//Last modified: 2021-05-12 23:36:57


struct Node {
    Node *l, *r;
    int key, val;
    Node(int _key, int _val) :key(_key), val(_val) {}
}*head, *tail; //两个哨兵

class LRUCache {
public:
    int n;
    unordered_map<int, Node*> hash;

    //从双链表删除掉p节点
    void remove(Node* p) {
        p -> l -> r = p -> r;
        p -> r -> l = p -> l;
    }

    //在头部(head后)插入p节点
    void insert(Node* p) {
        p -> l = head;
        p -> r = head -> r;
        head -> r = p;
        p -> r -> l = p;
    }

    LRUCache(int capacity) {
        n = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> r = tail;
        tail -> l = head;
    }
    
    int get(int key) {
        if (!hash.count(key)) return -1;
        Node* p = hash[key];
        //使用过一次，把他插入到链表的头部
        remove(p);
        insert(p);
        return p -> val;
    }
    
    void put(int key, int value) {
        if (hash.count(key)) {
            hash[key] -> val = value;
            Node* p = hash[key];
            remove(p);
            insert(p);
        } else {
            if (hash.size() == n) {
                Node* p = tail -> l;
                remove(p);
                hash.erase(p -> key);
                delete p;
            }
            Node* q = new Node(key, value);
            hash[key] = q;
            insert(q);
        }
    }
};

int main() {
    return 0;
}

