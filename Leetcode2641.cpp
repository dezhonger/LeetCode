class Solution {
public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        root->val = 0;
        vector<TreeNode*> q = {root};
        while (!q.empty()) {
            vector<TreeNode*> nxt;
            int next_level_sum = 0; // 下一层的节点值之和
            for (auto node: q) {
                if (node->left) {
                    nxt.push_back(node->left);
                    next_level_sum += node->left->val;
                }
                if (node->right) {
                    nxt.push_back(node->right);
                    next_level_sum += node->right->val;
                }
            }

            // 再次遍历，更新下一层的节点值
            for (auto node: q) {
                int children_sum = (node->left ? node->left->val : 0) +
                                   (node->right ? node->right->val : 0);
                if (node->left) node->left->val = next_level_sum - children_sum;
                if (node->right) node->right->val = next_level_sum - children_sum;
            }
            q = nxt;
        }
        return root;
    }
};
