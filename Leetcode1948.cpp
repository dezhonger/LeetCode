//https://leetcode-cn.com/problems/delete-duplicate-folders-in-system/solution/shan-chu-xi-tong-zhong-de-zhong-fu-wen-j-ic32/
struct Trie {
    // 当前节点结构的序列化表示
    string serial;
    // 当前节点的子节点
    unordered_map<string, Trie*> children;
};

class Solution {
public:

    unordered_map<string, int> hashTree;
    
    void dfs(Trie* node) {
        if (node -> children.empty()) return ;
        vector<string> v;
        for (auto& [k, vv]: node -> children) {
            dfs(vv);
            v.push_back(k + "(" + vv -> serial + ")");
        }
        
        sort(v.begin(), v.end());
        for(auto& s: v) node -> serial += move(s);
        hashTree[node -> serial]++;
    }
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        hashTree.clear();
        Trie* root = new Trie();
        
        //先构造出来Trie
        for(auto& s: paths) {
            auto cur = root;
            for (auto& node: s) {
                // 没有这个节点
                if (!cur->children.count(node)) cur->children[node] = new Trie();
                cur = cur -> children[node];
            }
        }
        
        dfs(root);
        
        vector<vector<string>> ans;
        vector<string> path;
        function<void(Trie*)> operate = [&](Trie* node) {
            if (hashTree[node -> serial] > 1) return ;
            //路径加入到答案里
            if (!path.empty()) ans.push_back(path);
            for (auto& [k, v]: node -> children) {
                path.push_back(k);
                operate(v);
                path.pop_back();
            }
        };
        operate(root);
        
        return ans;
    }
};
