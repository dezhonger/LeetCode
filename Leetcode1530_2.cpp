//Time complexity  O(n * distance)
class Solution {
public:
    #define pb push_back
    int ans, dis;
    
    vector<int> solve(TreeNode* root) {
        vector<int> d(dis, 0);
        if (!root) return d;
        if (!root -> left && !root -> right) {
            d[0] = 1;
            return d;
        }
        vector<int> l = solve(root -> left);
        vector<int> r = solve(root -> right);
        vector<int> sr(dis);
        sr[0] = r[0];
        for (int i = 1; i < dis; i++) sr[i] = sr[i - 1] + r[i];
        for (int i = 0; i < dis - 1; i++) ans += l[i] * sr[dis - 2 - i];
        for (int i = 0; i < dis - 1; i++) d[i + 1] = l[i] + r[i];
        return d;
    }
    
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        dis = distance;
        solve(root);
        return ans;
    }
};
