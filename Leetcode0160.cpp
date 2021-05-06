#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0160.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-06 19:44:45
//Last modified: 2021-05-06 19:44:55

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            if (!p) p = headB;
            else p = p -> next;
            if (!q) q = headA;
            else q = q -> next;
        }
        return p;
    }
};
