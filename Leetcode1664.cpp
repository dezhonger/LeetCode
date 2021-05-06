#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1664.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-07 03:28:37
//Last modified: 2021-05-07 03:43:32


#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1664.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-07 03:28:37
//Last modified: 2021-05-07 03:43:32

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(2, vector<int>(n));
        vector<vector<int>> g(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int c = nums[i];
            if (i & 1) {
                if (i >= 2) f[1][i] = f[1][i - 2] + c;
                else f[1][i] = c;
                if (i > 0) f[0][i] = f[0][i - 1];
            } else {
                if (i >= 2) f[0][i] = f[0][i - 2] + c;
                else f[0][i] = c;
                if (i > 0) f[1][i] = f[1][i - 1];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int c = nums[i];
            if (i & 1) {
                if (i + 2 < n) g[1][i] = g[1][i + 2] + c;
                else g[1][i] = c;
                if (i + 1 < n) g[0][i] = g[0][i + 1];
            } else {
                if (i + 2 < n) g[0][i] = g[0][i + 2] + c;
                else g[0][i] = c;
                if (i + 1 < n) g[1][i] = g[1][i + 1];
            }
        }
        


        int r = 0;
        for (int i = 0; i < n; i++) {
            int odd = 0, even = 0;
            if (i > 0) {
                odd += f[1][i - 1];
                even += f[0][i - 1];
            }

            if (i + 1 < n) {
                //删除一位后，奇偶性交换
                odd += g[0][i + 1];
                even += g[1][i + 1];
            }
            if (odd == even) r++;
        }
        return r;
    }
};


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

