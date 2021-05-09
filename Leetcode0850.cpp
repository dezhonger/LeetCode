#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0850.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-10 01:32:34
//Last modified: 2021-05-10 01:46:01

#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;

const int mod = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:

    LL cal(vector<vector<int>>& r, int a, int b) {
        if (a == b) return 0;
        vector<PII> v;
        LL sum = 0;
        for (auto& x: r) {
            if (x[0] <= a && x[2] >= b) {
                //包含在两条扫描线之间
                v.push_back(make_pair(x[1], x[3]));
            }
        }
        //区间合并操作
        sort(v.begin(), v.end());
        int s = -1, e = -1;
        for (auto& x : v) {
            if (x.F > e) {
                sum += e - s;
                s = x.F, e = x.S;
            } else if (x.S > e) {
                e = x.S;
            }
        }
        sum += e - s;
        //cout << a << " " << b << " " << sum << endl;
        return sum * (b - a);
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        LL res = 0;
        vector<int> v;
        for (auto& x : rectangles) {
            v.push_back(x[0]);
            v.push_back(x[2]);
        }
        sort(v.begin(), v.end());
        
        for (int i = 1; i < v.size(); i++) {
            res += cal(rectangles, v[i - 1], v[i]);
        }
        return res % mod;

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

