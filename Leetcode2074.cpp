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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int i = 0;
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while (cur)
        {
            i++;
            ListNode* it = cur;
            int len = 0;
            while (len < i && it) it = it -> next, len++;
            
            if (len & 1) for (int j = 1; j <= len; j++) pre = cur, cur = cur -> next;
            else
            {
                ListNode* ppre = nullptr;
                ListNode* ccur  = cur;
                for (int j = 1; j <= len; j++)
                {
                    ListNode *nxt = cur->next;
                    cur -> next = ppre;
                    ppre = cur;
                    cur = nxt;
                    // if (len == 2 && ppre && cur) cout << ppre -> val << " " << cur -> val << endl; 
                }
                pre -> next = ppre;
                pre = ccur;
                ccur -> next = cur;
            }
        }
        return head;
    }
};
