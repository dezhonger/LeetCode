#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0457.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-06 18:24:04
//Last modified: 2021-05-06 18:39:58

class Solution {
    public:
        bool circularArrayLoop(vector<int>& nums) {
            int base = 10000;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (nums[i] >= base) continue;
                int pos = i, flag = base + i;
                int last = -1, t = nums[i] > 0;
                do {
                    int nxt = (((nums[pos] + pos) % n) + n) % n;
                    last = nums[pos];
                    nums[pos] = flag;
                    pos = nxt;
                    //while里的条件：  nums[pos] < base：没有没遍历过的数，因为遍历过的数一定都 >= base 
                    //(t ^ (nums[pos] > 0)) ：符号相同，都是正数，或者都是负数
                }while (nums[pos] < base && (t ^ (nums[pos] > 0)) == 0);
                //last % n == 0 表示是自换环
                if (last % n == 0) continue;
                //遍历到这里遍历过的数
                if (nums[pos] == flag) return true;
            }
            return false;
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

