#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0004.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-08 02:30:29
//Last modified: 2021-05-08 03:02:14

#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0004.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-08 02:30:29
//Last modified: 2021-05-08 03:02:14

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot % 2 == 0) {
            int l = find(nums1, 0, nums2, 0, tot / 2);
            int r = find(nums1, 0, nums2, 0, tot / 2 + 1);
            cout << l << " " << r << endl;
            return (l + r) / 2.0;
        } else {
            return find(nums1, 0, nums2, 0, tot / 2 + 1);
        }
    }

    //第一个数组从i开始，第二个数组从j开始。合并排序后第k个数(这里k从1开始)是多少
    int find(vector<int>& n1, int i, vector<int>& n2, int j, int k) {
        //我们保证n1.size() < n2.size()
        int l1 = n1.size() - i, l2 = n2.size() - j;
        if (l1 > l2) return find(n2, j, n1, i, k);
        //第一个数组为空
        if (i == n1.size()) return n2[j + k - 1];
        if (k == 1) return min(n1[i], n2[j]);

        int r1 = k / 2, r2 = k - r1;
        //表示的是下一个数
        int s1 = min(i + r1, (int)n1.size()), s2 = min(j + r2, (int)n2.size());
        if (n1[s1 - 1] > n2[s2 - 1]) {
            //说明n2数组从j开始到s2内的数不可能是答案, 排除掉
            return find(n1, i, n2, s2, k - (s2 - j));
        } else {
            //说明n1数组从i开始到s1内的数不可能是答案, 排除掉
            //这里不能直接返回n1[s1 - 1]，因为有可能 (s1 - i) + (s2 - j) 不够k个数。也就是说n1数组内已经不够k/2个数了
            return find(n1, s1, n2, j, k - (s1 - i));
        }
        return 0;
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

