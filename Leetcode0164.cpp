#include <bits/stdc++.h>
using namespace std;
//题解：https://blog.csdn.net/qq_41231926/article/details/86377976

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int Min = INT_MAX;
        int Max = INT_MIN;
        
        for (auto x : nums) {
            Min = min(Min, x);
            Max = max(Max, x);
        }
        if (Min == Max || n <= 1) return 0;
        int sz = (Max - Min + n) / (n + 1);
        int fmin[n + 1], fmax[n + 1], visit[n + 1];
        memset(visit, 0, sizeof visit);

        for (auto x : nums) {
            //应该在哪个桶
            int bucket = (x - Min) / sz;
            //最大的数
            if (x == Max) bucket = n;
            if (visit[bucket] == 0) {
               fmin[bucket] = fmax[bucket] = x;
               visit[bucket] = 1;
            } else {
                fmin[bucket] = min(fmin[bucket], x);
                fmax[bucket] = max(fmax[bucket], x);
            }
        }
        
        int ans = 0;
        int pre = fmax[0];
        for (int i = 1; i <= n; i++) {
            if (visit[i]) {
                ans = max(ans, fmin[i] - pre);
                pre = fmax[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {3,6,9,1};
    cout << s.maximumGap(v) << endl;

    return 0;
}