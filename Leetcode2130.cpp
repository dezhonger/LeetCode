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
// https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/solution/lian-biao-zui-da-luan-sheng-he-by-leetco-uoc7/
    int pairSum(ListNode* head) {
        // s = slow, f = fast
        ListNode* s = head, *f = head -> next;
        while (f -> next) s = s -> next, f = f -> next -> next;

        //reverse link
        ListNode* last = s -> next; // 后半部分的第一个节点
        while (last -> next)
        {
            ListNode* cur = last -> next;
            last -> next = cur -> next;
            cur -> next = s -> next;
            s -> next = cur;
        }

        int ans = 0;
        ListNode* x = head, *y = s -> next;
        while (y)
        {
            ans = max(ans, x -> val + y -> val);
            x = x -> next;
            y = y -> next;
        }
        return ans;
    }
};
