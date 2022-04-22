vector<vector<int>> g;
class Solution {
public:
    int ans = 0;
    int dfs(int node, string& s) {
        int maxLen = 0;
        for (int j: g[node]) {
            int len = dfs(j, s) + 1;
            if (s[j] != s[node]) {
                ans = max(ans, maxLen + len);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        ans = 0;
        g = vector<vector<int>>(n);
        for (int i = 1; i < n; i++) g[parent[i]].push_back(i);
        dfs(0, s);
        return ans + 1;
    }
};

