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
    int h;
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode* rr = root;
        h = 0;
        while (rr -> left) rr = rr -> left, h++;
        int l = 1 << h, r = (1 << (h + 1)) - 1;
        //cout << l << " " << r << endl;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (exist(mid, root)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    bool exist(int x, TreeNode* root) {
        for (int i = h - 1; i >= 0; i--) {
            if (x & (1 << i)) root = root -> right;
            else root = root -> left;
            if (!root) return false;
        }
        return root != NULL;
    }
};
