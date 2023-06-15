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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        if (!head) return {-1, -1};
        int pos = 0;
        while (head -> next)
        {
            ++pos;
            if (!(head -> next -> next)) break;
            int last = head -> val;
            int cur = head -> next -> val;
            int nxt = head -> next -> next -> val;
            if (cur < last && cur < nxt) v.push_back(pos);
            else if (cur > last && cur > nxt) v.push_back(pos);
            head = head -> next;
        }
        if (v.size() < 2) return {-1, -1};
        vector<int> res{INT_MAX, v.back() - v[0]};
        for (int i = 1; i < v.size(); i++) res[0] = min(res[0], v[i] - v[i - 1]);
        return res;
    }
};
