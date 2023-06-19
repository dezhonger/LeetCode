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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> fa;
        TreeNode* s = nullptr;
        TreeNode* t = nullptr;

        function<void(TreeNode*)> dfs = [&](TreeNode* cur)
        {
            if (cur -> val == startValue) s = cur;
            if (cur -> val == destValue) t = cur;
            if (cur -> left) fa[cur -> left] = cur, dfs(cur -> left);
            if (cur -> right) fa[cur -> right] = cur, dfs(cur -> right);
        };

        dfs(root);

        // 求出根节点到对应节点的路径字符串
        function<string(TreeNode*)> path = [&](TreeNode* cur)
        {
            string res;
            while (cur != root)
            {
                auto par = fa[cur];
                if (par -> left == cur) res.push_back('L');
                else res.push_back('R');
                cur = par;
            }
            reverse(res.begin(), res.end());
            return res;
        };

        string path1 = path(s), path2 = path(t);
        int l1 = path1.size(), l2 = path2.size();
        // cout << path1 << endl;
        // cout << path2 << endl;
        // cout << l1 << l2 << endl;
        int i = 0;
        while (i < min(l1, l2)) {
            // cout << path1[i] << " " << path2[i] << endl;
            if (path1[i] == path2[i]) {
                ++i;
            }
            else {
                break;
            }
        }
        string finalpath(l1 - i, 'U');   // 最短路径对应字符串 
        finalpath.append(path2.substr(i));
        return finalpath;
    }
};
