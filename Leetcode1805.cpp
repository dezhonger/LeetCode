#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1805.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-14 23:14:19
//Last modified: 2021-05-14 23:21:53

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> s;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (isalpha(word[i])) continue;
            int j = i;
            while (j < n && isdigit(word[j])) j++;
            string str = word.substr(i, j - i);
            i = j - 1;
            if (str[0] == '0') {
                j = 0;
                while (j < str.size() && str[j] == '0') j++;
                if (j == str.size()) str = "0";
                else str = str.substr(j);
            }
            
            s.insert(str);
        }
        return s.size();
    }
};


