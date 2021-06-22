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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto pre = list1;
        for (int i = 0; i < a - 1; i++) {
            pre = pre -> next;
        }
        auto q = pre -> next;
        pre -> next = list2;
        for (int i = 0; i < b - a; i++) {
            q = q -> next;
        }
        auto tail = list2;
        while (tail -> next != NULL) tail = tail -> next;
        tail -> next = q -> next;
        q -> next = NULL;
        return list1;
    }
};
