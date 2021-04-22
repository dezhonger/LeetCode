#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0460.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-22 23:58:19

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;

#define Debug(x) cout<<#x<<"="<<x<<endl;

typedef long long LL;

//双链表套双链表
//每一个block表示所有访问次数相同的点
//每一个blcok内有多个node,头结点是最近被访问的节点
class LFUCache {
	public : 
		struct Node {
			Node *left, *right;
			int key, val;
			Node(int _key, int _val) {
				this -> key = _key;
				this -> val = _val;
				left = right = NULL;
			}
		};

		struct Block {
			Block *left, *right;
			Node *head, *tail; //每个块内的头尾节点

			int cnt;//这个块内所有节点都是被访问了cnt次
			Block(int _cnt) {
				this -> cnt = _cnt;
				left = right = NULL;
				head = new Node(-1, -1), tail = new Node(-1, -1);//为了代码方便，维护两个哨兵
				head -> right = tail, tail -> left = head;
			}

			~Block() {
				delete head;
				delete tail;
			}

			void insert(Node *p) {
				//插入到块内的第一个节点
				p -> right = head -> right;
				head -> right -> left = p;
				head -> right = p;
				p -> left = head;
			}

			void remove(Node *p) {
				p -> left -> right = p -> right;
				p -> right -> left = p -> left;
			}

			bool empty() {
				return head -> right == tail;
			}
		}*head, *tail;// 维护两个哨兵

		int n;
		unordered_map<int, Block*> hash_block;
		unordered_map<int, Node*> hash_node;

		void insert(Block *p) {
			//在p的右侧插入一个新块，cnt为当前块的cnt+1
			auto cur = new Block(p -> cnt + 1);
			cur -> right = p -> right;
			p -> right -> left = cur;
			p -> right = cur;
			cur -> left = p;
		}

		void remove(Block* p) {
			p -> left -> right = p -> right;
			p -> right -> left = p -> left;
			delete p;
		}


		LFUCache(int capacity) {
			this -> n = capacity;
			head = new Block(0), tail = new Block(INT_MAX);
			head -> right = tail, tail -> left = head;
		}

		int get(int key) {
			if (hash_block.count(key) == 0) return -1;
			auto block = hash_block[key];
			auto node = hash_node[key];
			block -> remove(node);
			if (block -> right -> cnt != block -> cnt + 1) insert(block);
			block -> right -> insert(node);
			hash_block[key] = block -> right;
			if (block -> empty()) remove(block);
			return node -> val;
		}

		void put(int key, int value) {
			if (n == 0) return ;
			if (hash_block.count(key)) {
				hash_node[key] -> val = value;
				get(key);//更新一次cnt
			} else {
				if (hash_block.size() == n) {
					auto p = head -> right -> tail -> left;
					head -> right -> remove(p);
					if (head -> right -> empty()) remove(head -> right);
					hash_block.erase(p -> key);
					hash_node.erase(p -> key);
					delete p;
				}
				auto p = new Node(key, value);
				if (head -> right -> cnt != 1) insert(head);
				head -> right -> insert(p);
				hash_block[key] = head -> right;
				hash_node[key] = p;
			}
		}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

