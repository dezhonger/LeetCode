class Solution {
public:

    TreeNode* ans;
    
    int dfs(TreeNode* r, TreeNode* p, TreeNode* q) {
        if (!r) return 0;
        int s = 0;
        if (r == p) s |= 1;
        else if (r == q) s |= 2;
        s |= dfs(r -> left, p, q);
        if (s == 3 && !ans) {
            ans = r;
            return s;
        }
        s |= dfs(r -> right, p, q);
        if (s == 3 && !ans) ans = r;
        return s;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        dfs(root, p, q);
        return ans;
    }

};
