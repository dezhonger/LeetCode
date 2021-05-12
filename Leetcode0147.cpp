#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0147.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-12 23:47:42
//Last modified: 2021-05-12 23:56:42


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* nxt = NULL;
        //依次遍历节点，插入到dummy开头的链表中的对应的位置
        for (ListNode* p = head; p; p = nxt) {
            nxt = p -> next;
            ListNode* cur = dummy;
            while (cur -> next && cur -> next -> val < p -> val) cur = cur -> next;
            if (cur -> next == NULL) {
                cur -> next = p;
                p -> next = NULL;
            } else {
                p -> next = cur -> next;
                cur -> next = p;
            }
        }
        return dummy -> next;
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

