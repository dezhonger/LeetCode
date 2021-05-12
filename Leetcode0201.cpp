#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0201.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-13 00:19:29
//Last modified: 2021-05-13 00:26:27

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int a = left >> i & 1;
            int b = right >> i & 1;
            if (a == b) res = res * 2 + a;
            else {
                res <<= (i + 1);
                break;
            }
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

