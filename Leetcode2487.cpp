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
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* nxt = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = reverse(head);
        head = cur;

        while (cur -> next)
        {
            if (cur -> val > cur -> next -> val) cur -> next = cur -> next -> next;
            else cur = cur -> next;
        }

        return reverse(head);
    }
};
