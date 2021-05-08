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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1), *last = NULL, *p;
        dummy -> next = head;
        p = dummy;
        int cnt = 0;
        while (p) {
            last = p;
            p = p -> next;
            cnt++;
            if (cnt == left) {
                ListNode* cur = p, *q = p -> next;
                for (int j = 0; j < right - left; j++) {
                    p -> next = q -> next;
                    q -> next = last -> next;
                    last -> next = q;
                    q = p -> next;
                }
                
            }
        }
        return dummy -> next;
    }
};
