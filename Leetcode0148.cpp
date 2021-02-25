#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0148.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-02-26 00:35:12


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int size = 0;
		for (auto p = head; p; p = p -> next) size++;
		for (int i = 1; i < n; i *= 2) {
			//每次合并长度为i的区间为2i的区间
			auto dummy = new ListNode(-1), cur = dummy;
			for (int j = 1; j <= n; j += i * 2) {
				auto p = head, q = p;
				for (int k = 0; k < i && q; k++) q = q -> next;//找到要合并的第二个区间的开头
				auto o = q;
				for (int k = 0; k < i && o; k++) o = o -> next;//下次循环使用，o表示下一次循环时候要合并的第一个区间的开头
				int l = 0, r = 0;
				while (l < i && r < i && p && q) {
					if (p -> val <= q -> val) cur = cur -> next = p, p = p -> next, l++;
					else cur = cur -> next = q, q = q -> next, r++;
				}
				while (l < i && p) cur = cur -> next = p, p = p -> next, l++;
				while (r < i && q) cur = cur -> next = q, q = q -> next, r++;
				head = o;
			}
			cur -> next = NULL;
			head = dummy -> next;
		}
		return head;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

