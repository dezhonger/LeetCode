class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};
