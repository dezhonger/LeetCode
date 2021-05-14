#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1163.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-08-21 00:05:50

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 400050;

class Solution {
    public:
        int n, m;
        char s[N];
        int sa[N], x[N], y[N], c[N], rk[N], height[N];
        

        void get_sa()
        {
            for (int i = 1; i <= n; i ++ ) c[x[i] = s[i]] ++ ;
            for (int i = 2; i <= m; i ++ ) c[i] += c[i - 1];
            for (int i = n; i; i -- ) sa[c[x[i]] -- ] = i;
            for (int k = 1; k <= n; k <<= 1)
            {
                int num = 0;
                for (int i = n - k + 1; i <= n; i ++ ) y[ ++ num] = i;
                for (int i = 1; i <= n; i ++ )
                    if (sa[i] > k)
                        y[ ++ num] = sa[i] - k;
                for (int i = 1; i <= m; i ++ ) c[i] = 0;
                for (int i = 1; i <= n; i ++ ) c[x[i]] ++ ;
                for (int i = 2; i <= m; i ++ ) c[i] += c[i - 1];
                for (int i = n; i; i -- ) sa[c[x[y[i]]] -- ] = y[i], y[i] = 0;
                swap(x, y);
                x[sa[1]] = 1, num = 1;
                for (int i = 2; i <= n; i ++ )
                    x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++ num;
                if (num == n) break;
                m = num;
            }
        }

        void get_height()
        {
            for (int i = 1; i <= n; i ++ ) rk[sa[i]] = i;
            for (int i = 1, k = 0; i <= n; i ++ )
            {
                if (rk[i] == 1) continue;
                if (k) k -- ;
                int j = sa[rk[i] - 1];
                while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k ++ ;
                height[rk[i]] = k;
            }
        }

        string lastSubstring(string ss) {
            //计算后缀数组下标从1开始
            n = ss.size();
            ss = " " + ss;
            strcpy(s,ss.c_str());
            m = 122;
            get_sa();
            //get_height();

            //for (int i = 1; i <= n; i ++ ) printf("%d ", sa[i]);
            //puts("");
            //for (int i = 1; i <= n; i ++ ) printf("%d ", height[i]);
            //puts("");
            return ss.substr(sa[n]);

        }

};

int main() {
    return 0;
}
