class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        //求长度
        auto p = head;
        while (p) {
            p = p -> next;
            len++;
        }
        
        auto dummy = new ListNode(-1);
        dummy -> next = head;
        int k2 = len - k + 1;
        if (k2 == k) return dummy -> next;
        if (k2 < k) swap(k, k2);
        

        
        auto q1 = dummy, q2 = dummy;
        for (int i = 0; i < k; i++) q1 = q1 -> next;
        for (int i = 0; i < k2; i++) q2 = q2 -> next;
        int v = q1 -> val;
        q1 -> val = q2 -> val;
        q2 -> val = v;
        return dummy -> next;
    }
};
