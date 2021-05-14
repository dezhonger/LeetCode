#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1800.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-14 23:24:24
//Last modified: 2021-05-14 23:27:08

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            int s = nums[i];
            while (j + 1 < n && nums[j + 1] > nums[j]) {
                j++;
                s += nums[j];
            }
            res = max(res, s);
        }
        return res;
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

