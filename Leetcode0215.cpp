#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0215.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-15 00:20:27
//Last modified: 2021-05-15 00:25:03

class Solution {
public:

    int findKth(vector<int>& a, int l, int r, int k) {
        if (l == r) return a[l];
        int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (a[i] < x);
            do j--; while (a[j] > x);
            if (i < j) swap(a[i], a[j]);
        }
        int c = j - l + 1;
        if (k <= c) return findKth(a, l, j, k);
        else return findKth(a, j + 1, r, k - c);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n + 1 - k;
        return findKth(nums, 0, n - 1, k);
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

