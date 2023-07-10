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
    set<int> ms;

    void dfs(TreeNode *node) {
        if (node == nullptr) return;
        ms.insert(node->val);
        dfs(node->left);
        dfs(node->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<vector<int>> ans;
        for (int x : queries) {
            if (ms.count(x)) ans.push_back({x, x});
            else
            {
                auto it = ms.upper_bound(x);
                int a = -1, b = -1;
                //it == ms.end() 意味着所有的数都小于x
                if (it != ms.end()) b = *it;
                if(it != ms.begin()) it--, a = *it;
                ans.push_back({a, b});
            }
        }
        return ans;
    }
};
