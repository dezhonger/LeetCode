/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int sz = 0;
        ListNode* h = head;
        while (h) h = h -> next, sz++;
        if (sz == 1) return nullptr;
        int del = sz / 2;
        h = head;
        int i = 1;
        while (i < del) i++, h = h -> next;
        h -> next = h -> next -> next;
        return head;

    }
};
