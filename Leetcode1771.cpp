#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1771.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-03 13:59:50

const int N = 1010;
int f[N][N];
int f2[N][N];
int f3[N][N];

class Solution {
public:

    void cal(string s, int f[][N]) {
        int n = s.size();
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len -1;
                if (len == 1) f[i][j] = 1;
                else {
                    if (s[i] != s[j]) f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                    else f[i][j] = f[i + 1][j - 1] + 2;
                }
            }
        }
    }

    int longestPalindrome(string a, string b) {
        int n = a.size(), m = b.size();
        reverse(b.begin(), b.end());
        memset(f, 0, sizeof f);
        memset(f2, 0, sizeof f2);
        memset(f3, 0, sizeof f3);
        a = ' ' + a, b = ' ' + b;
        cal(a, f2); cal(b, f3);
        //LCS
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j]) f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j]);
                else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (f[i][j]) res = max(res, f[i][j] * 2 + max(f2[i + 1][n], f3[j + 1][m]));
            }
        }
        
 
        return res;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

