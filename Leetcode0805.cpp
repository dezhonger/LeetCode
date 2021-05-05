#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0805.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-06 01:52:10
//Last modified: 2021-05-06 02:02:09

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;

#define Debug(x) cout<<#x<<"="<<x<<endl;
typedef pair<int, int> PII;

class Solution {
    public:
        bool splitArraySameAverage(vector<int>& nums) {
            int n = nums.size();
            int n1 = n / 2;
            int n2 = n - n1;

            int sum = 0;
            for (int x: nums) sum += x;

            set<PII> st;
            //枚举前一半数组
            for (int i = 0; i < (1 << n1); i++) {
                int c = 0, s = 0;
                for (int j = 0; j < n1; j++) {
                    if (i & (1 << j)) s += nums[j], c++;
                }
                st.insert({s, c});
            }

            //枚举后一半数组
            for (int i = 0; i < (1 << n2); i++) {
                int c = 0, s = 0;
                for (int j = 0; j < n2; j++) {
                    if (i & (1 << j)) s += nums[j + n1], c++;
                }

                for (int cc = max(1, c); cc < n; cc++) {
                    if (cc * sum % n == 0) {
                        //sum / n == xxx / cc 满足这个条件
                        //后一半已经有c个数的和为s
                        int ss = cc * sum / n;
                        //就是说需要在前一半数组内找到 cc - c 个数的和为s - ss
                        PII p(ss - s, cc - c);
                        if (st.count(p)) return true;
                    }
                }

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

