class Solution {
public:
    #define pb push_back
    int ans, dis;
    
    vector<int> solve(TreeNode* root) {
        if (!root) return vector<int>();
        if (!root -> left && !root -> right) return vector<int>{0};
        vector<int> l = solve(root -> left);
        vector<int> r = solve(root -> right);
        vector<int> d;
        //双指针求出来和小于dis的pair数
        for (int i = 0, j = r.size() - 1; i < l.size(); i++){
            while (j >= 0 && l[i] + r[j] + 2 > dis) j--;
            ans += j + 1;
        }
        //归并数组
        int i = 0, j = 0;
        while (i < l.size() && j < r.size()) {
            if (l[i] < r[j]) d.pb(l[i++] + 1);
            else d.pb(r[j++] + 1);
        }
        while (i < l.size()) d.pb(l[i++] + 1);
        while (j < r.size()) d.pb(r[j++] + 1);
        return d;
    }
    
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        dis = distance;
        solve(root);
        return ans;
    }
};
