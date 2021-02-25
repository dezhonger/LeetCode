#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode133.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-02-26 00:06:58

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

	unordered_map<Node*, Node*> hash;


    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

		//copy points
		dfs(node);

		//copy edge
		dfs2();

		return hash[node];
    }

	void dfs(Node* node) {
		hash[node] = new Node(node -> val);
		for (auto ver: node -> neighbors) {
			if (hash.count(ver) == 0) dfs(ver);
		}
	}

	void dfs2() {
		for (auto [s, d]: hash) {
			for (auto ver: s -> neighbors) {
				d -> neighbors.push_back(hash[ver]);
			}
		}
	}
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

