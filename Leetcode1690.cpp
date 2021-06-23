const int N = 1010;
class Solution {
public:
    vector<int> s;
    int dp[N][N], v[N][N];
    inline int get(int l, int r) {

        return s[r + 1] - s[l];
    }
    
    int dfs(int l, int r) {
        if (l == r) return 0;
        if (v[l][r] != -1) return dp[l][r];
        int a = get(l + 1, r) - dfs(l + 1, r);
        int b = get(l, r - 1) - dfs(l, r - 1);
        v[l][r] = 1;
        return dp[l][r] = max(a, b);
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        s = vector<int>(n + 1);
        memset(v, -1, sizeof v);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + stones[i - 1];
        return dfs(0, n - 1);
    }
};
