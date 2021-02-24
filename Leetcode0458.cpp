#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0458.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-02-24 23:25:07

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k = minutesToTest/ minutesToDie + 1;
		return ceil(log(buckets) / log(k));
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

