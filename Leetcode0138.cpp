#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0138.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-07 03:52:16
//Last modified: 2021-05-07 04:12:09

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};




class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* h = head;
        while (h != NULL) {
            Node* c = new Node(h -> val);
            c -> next = h -> next;
            h -> next = c;
            h = c -> next;
        }
        h = head;
        while (h != NULL) {
            Node* p = h, *q = h -> random;
            if (q == NULL) p -> next -> random = NULL;
            else p -> next -> random = q -> next;
            h = h -> next -> next;
        }

        Node* hh = head -> next, *res = hh;
        h = head;
        while (h != NULL) {
            h -> next = hh -> next;
            if (h -> next != NULL) hh -> next = h -> next -> next;
            
            h = h -> next;
            hh = hh -> next;
        }
        return res;
    }
};


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

