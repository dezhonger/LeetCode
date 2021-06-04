class Solution {
public:
    int ans;

    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if (!root->left || root->left->val != root->val) l = 0;
        if (!root->right || root->right->val != root->val) r = 0;
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};
