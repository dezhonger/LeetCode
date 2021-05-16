/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        vector<Node*> res = dfs(head);
        return res[0];
    }
    vector<Node*> dfs(Node* head) {
        if (!head) return {NULL, NULL};
        //tail 最后一个不null的节点
        Node* cur = head, *tail = head;
        while (cur) {
            tail = cur;
            if (cur -> child == NULL) {
                cur = cur -> next;
            } else {
                vector<Node*> t = dfs(cur -> child);
                cur -> child = NULL;
                t[1] -> next = cur -> next;
                if (t[1] -> next != NULL) t[1] -> next -> prev = t[1];
                cur -> next = t[0];
                t[0] -> prev = cur;
                cur = t[1] -> next;
                tail = t[1];
            }
        }
        return {head, tail};
    }
};
