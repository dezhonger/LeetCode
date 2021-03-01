#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int res = -1;
    
    void dfs(int sum, int idx, vector<int>& b, int t) {
        if (idx == b.size()) {
            if (res == -1 || abs(sum - t) < abs(res - t) || (abs(sum - t) == abs(res - t) && sum < res)) res = sum;
            return ;
        }
        dfs(sum, idx + 1, b, t);
        dfs(sum + b[idx], idx + 1, b, t);
        dfs(sum + 2 * b[idx], idx + 1, b, t);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for (int i = 0; i < baseCosts.size(); i++) {
            dfs(baseCosts[i], 0, toppingCosts, target);
        }
        return res;
    }
};