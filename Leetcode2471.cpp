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
    vector<vector<int>> vec;

    // 把同一层的数都集中到同一个序列里
    void dfs(TreeNode *node, int d) {
        if (node == nullptr) return;
        while (vec.size() <= d) vec.push_back(vector<int>());
        vec[d].push_back(node->val);
        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }

    int gao(vector<int> &A) {
        // 求每个元素的目标位置
        vector<int> B = A;
        sort(B.begin(), B.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < B.size(); i++) mp[B[i]] = i;

        int ret = 0;
        for (int i = 0; i < A.size(); i++) {
            // 不断将 A[i] 交换到目标位置，直到 A[i] = B[i]
            // 注意别写成 if 了
            while (A[i] != B[i]) {
                swap(A[i], A[mp[A[i]]]);
                ret++;
            }
        }
        return ret;
    }

public:
    int minimumOperations(TreeNode* root) {
        dfs(root, 0);
        int ans = 0;
        for (auto &A : vec) ans += gao(A);
        return ans;
    }
};
