#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0142.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-06 17:47:50
//Last modified: 2021-05-06 17:55:34


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *s = head, *f = head;
            // s:slow f:fast
            while (f != NULL && f -> next != NULL) {
                s = s -> next;
                f = f -> next -> next;
                if (f == s) {
                    s = head;
                    cout << s -> val << endl;
                    while (f != s) f = f -> next, s = s -> next;
                    return f;
                }
            }
            return NULL;
        }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

