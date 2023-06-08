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
    bool check(TreeNode* root)
    {
        if (!root) return 1;
        int rv = root -> val, l, r;
        if (!(root -> left) && !(root -> right)) return 1;
        if (!(root -> left)) l = 0;
        else l = root -> left -> val;
        if (!(root -> right)) r = 0;
        else r = root -> right -> val;
        return rv == l + r;
    }
    bool checkTree(TreeNode* root) {
        if (!root) return 1;
        return check(root) && checkTree(root -> left) && checkTree(root -> right);
    }
};
