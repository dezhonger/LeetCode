//https://leetcode-cn.com/problems/merge-bsts-to-create-single-bst/solution/he-bing-duo-ke-er-cha-sou-suo-shu-by-lee-m42t/
class Solution {
public:
    //维护中序遍历的上一个值，保持单调性
    int pre;
    //存储所有叶子节点的值
    unordered_set<int> leaf;
    //存储映射关系，key:树的根节点 value:树本身
    unordered_map<int, TreeNode*> rtmp;
        
    bool dfs(TreeNode* t) {
        if (!t) {
            return true;
        }
        
        //遍历到叶子节点的时候，去尝试合并其他的数
        if (!t -> left && !t -> right && rtmp.count(t -> val)) {
            // 这个叶子节点可以接一个树
            auto nxt = rtmp[t -> val];
            rtmp.erase(t -> val);
            t -> left = nxt -> left;
            t -> right = nxt -> right;
            
        }
        
        if (!dfs(t -> left)) return false;
        if (pre >= t -> val) return false;
        pre = t -> val;
        if (!dfs(t -> right)) return false;
        return true;
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        leaf.clear();
        rtmp.clear();
        
        for (auto& tr: trees) {
            rtmp[tr -> val] = tr;
            //题目保证树最多只有两层
            if (tr -> left) leaf.insert(tr -> left -> val);
            if (tr -> right) leaf.insert(tr -> right -> val);
        }
        
        // 如果最后可以形成一颗BST，那么这课BST的根结点的值一定在不在leaf中出现过
        // 证明：否则就会有两个相同的值，根据题意就不是BST了
        
        for (auto& tr: trees) {
            if (!leaf.count(tr -> val)) {
                //如果最后有答案的话，那么根结点就是这棵树的根结点
                rtmp.erase(tr -> val);
                bool ans = dfs(tr);
                return (ans && rtmp.empty()) ? tr : nullptr;
                
            }
        }
        return nullptr;
    }
};
