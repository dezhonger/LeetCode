#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int MOD = 1000000007;
int f[N][N][N];
int g[N][N];

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        //1 计算使用人数不超过n的计划方案数
        //2 计算使用人数不超n盈利小于 minProfit 的方案数
        //1-2 即为使用人数不超n，且盈利 >= minProfit 的方案数
        
        int sz = group.size();
        g[0][0] = 1;
        for (int i = 1; i <= sz; i++) {
            int cnt = group[i - 1];
            for (int j = 1; j <= n; j++) {
                if (j >= cnt) g[i][j] += g[i - 1][j - cnt];
            }
        }
        
        int all = 0;
        for (int j = 1; j <= n; j++) all += g[sz][j];
        cout << "all: " << all << endl; 
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k < minProfit; k++) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (i >= 1 && j >= group[i - 1] && k >= profit[i - 1])
                        f[i][j][k] = f[i - 1][j - group[i - 1]][k - profit[i - 1]];
                     
                }
            }
        }

        int ans = 0;
        return ans;

    }
};