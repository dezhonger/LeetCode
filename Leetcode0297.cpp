/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfs(root);
    }
    
    string dfs(TreeNode* root) {
        if (root == NULL) return "#,";
        string res = to_string(root -> val) + ",";
        res += dfs(root -> left);
        res += dfs(root -> right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return dfs(data, i);
    }
    
    TreeNode* dfs(string& d, int& i) {
        if (d[i] == '#') {
            i += 2;
            return NULL;
        }
        int u = i;
        while (d[i] != ',') i++;
        int val = stoi(d.substr(u, i));
        TreeNode* tr = new TreeNode(val);
        
        //跳过逗号
        i++;
        tr -> left = dfs(d, i);
        tr -> right = dfs(d, i);
        return tr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
