#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0162.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-11 23:11:36
//Last modified: 2021-05-11 23:15:31

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - ;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
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

