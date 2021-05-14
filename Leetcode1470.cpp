#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1470.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-14 22:48:53
//Last modified: 2021-05-14 22:54:03

class Solution {
public:

    int n;
    inline int getPos(int x) {
        if (x < n) return x * 2;
        return (x - n) * 2 + 1;
    }

    vector<int> shuffle(vector<int>& nums, int _n) {
        n = _n;
        for (int i = 0; i < n * 2; i++) {
            int j = i;
            while (nums[i] > 0) {
                //负数表示正确的数已经在正确的位置了
                j = getPos(j);
                //nums[j]这个时候存储的就是正确的数了
                swap(nums[i], nums[j]);
                nums[j] = -nums[j];
            }
        }
        for (int i = 0; i < 2 * n; i++) nums[i] = -nums[i];
        return nums;
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

