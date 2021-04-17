#define Debug(x) cout<<#x<<"="<<x<<endl;

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
    // 返回头尾节点
    vector<ListNode*> reverse(ListNode* head, int k) {
        ListNode* tail = head;
        ListNode* p = head;
        ListNode* q = head -> next;
        int c = 0;
        while(c++ < k - 1) {
            p -> next = q -> next;
            q -> next = head;
            head = q;
            q = p -> next;
        }
        return {head, tail};
    }
    

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == NULL) return head;
        
        ListNode* ans = head;
        bool f = false;
        vector<ListNode*> last = {NULL, NULL};
        ListNode* h1 = head;
        ListNode* hh1 = head;
        while (true) {
            int c = 0;
            while (h1 && ++c < k) h1 = h1 -> next;
            
            if (c == k) {
                vector<ListNode*> vr = reverse(hh1, k);
                if (!f) {ans = vr[0]; f = true;}
                //上一组的尾和这一组的头连接
                if (last[1] != NULL) last[1] -> next = vr[0];
                //h1指向下一组的头
                h1 = vr[1] -> next;
                last = vr;
            } else {
                if (last[1] != NULL) last[1] -> next = hh1;
            }
            if (h1 == NULL) break;
            hh1 = h1;
            
        }
        return ans;

        
    }
};
