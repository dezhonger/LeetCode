/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root;
    }
    void del(TreeNode* &root, int key) {
        if (root == NULL) return ;
        if (key == root -> val) {
            if (!root -> left && !root -> right) root = NULL;
            else if (!root -> left) root = root -> right;
            else if (!root -> right) root = root -> left;
            else {
                //找到后继节点
                TreeNode* p = root -> right;
                while (p -> left) p = p -> left;
                root -> val = p -> val;
                del(root -> right, root -> val);
            }
        }
        else if (key < root -> val) del(root -> left, key);
        else del(root -> right, key);
    }
};
