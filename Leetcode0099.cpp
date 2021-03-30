#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0099.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-03-30 21:12:52
//https://www.acwing.com/solution/content/181/
//Morris-traversal算法

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:

	void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *prep = NULL;
        while(root) {
            if (!root -> left) {
                //没有左子树
                if (prep && prep -> val > root -> val) {
                    if (!first) first = prep, second = root;
                    else second = root;
                }
                prep = root;
                root = root -> right;
            } else {
                TreeNode *p = root -> left;
                while (p -> right && p -> right != root) p = p -> right;
                if (!p -> right) {
                    //第一次遍历到root
                    p -> right = root;
                    root = root -> left;
                } else {
                    //回溯到了root
                    p -> right = NULL;
                    if (prep && prep -> val > root -> val) {
                        if (!first) first = prep, second = root;
                        else second = root;
                    }
                    prep = root;
                    root = root -> right;
                }
            }
        }
        swap(first -> val, second -> val);
	}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

