class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* st = nullptr;
        map<TreeNode*, TreeNode*> parents;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* pa){
            if(node == nullptr) return;
            //找到开始节点
            if(node->val == start) st = node;

            parents[node] = pa;
            dfs(node->left, node);
            dfs(node->right, node);
        };
        dfs(root, nullptr);

        int res = -1;

        unordered_map<TreeNode*, bool> visited{{st, true}, {nullptr, true}};
        
        queue<TreeNode*> q;
        q.push(st);
        while(!q.empty()){           
            int len = q.size();
            for(int i = 0; i < len; ++i){
                TreeNode* node = q.front(); q.pop();
                if(node != nullptr){
                    if(!visited[node->left]){
                        visited[node->left] = true;
                        q.push(node->left);
                    }
                    if(!visited[node->right]){
                        visited[node->right] = true;
                        q.push(node->right);
                    }
                    if(!visited[parents[node]]){
                        visited[parents[node]] = true;
                        q.push(parents[node]);
                    }
                }
            }
            res++;
        }
        return res;    
    }
};
