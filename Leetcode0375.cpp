#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//dp[i][j] = min(k + max(dp[i][k-1], dp[k+1][j])

class Solution {
public:
    int dfs(vector<vector<int>>& dp, int l, int r) {
        if(l >= r) return 0;
        if(dp[l][r] != 0) return dp[l][r];
        dp[l][r] = 0x7fffffff;
        for(int i = l; i <= r; i++) {
            dp[l][r] = min(dp[l][r], i + max(dfs(dp, l, i - 1), dfs(dp, i + 1, r)));
        }
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dfs(dp, 1, n);
        return dp[1][n];
    }
};

int main()
{
    Solution s;
    cout << s.getMoneyAmount(2);
    return 0;
}
