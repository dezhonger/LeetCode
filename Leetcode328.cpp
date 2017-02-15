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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* odd = head;
        if(head == NULL) return head;
        ListNode* even = head -> next;
        if(even == NULL) return head;
        ListNode* Head = head;
        ListNode* Head2 = head -> next;
        while(even && even -> next) {
            odd -> next = even -> next;
            odd = odd -> next;
            even ->next = odd -> next;
            even = even -> next;    
        }
        odd -> next = Head2;
        return Head;
    }
};
