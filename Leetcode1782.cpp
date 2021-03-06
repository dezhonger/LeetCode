#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1782.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//https://leetcode-cn.com/problems/count-pairs-of-nodes/solution/rong-chi-yuan-li-li-qing-si-lu-zhu-bu-yo-yl38/

//Create: 2021-03-07 00:40:24

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
		vector<int> d(n + 1);//度数, 1-base
		unordered_map<int, int> cnt;
		for (auto& e: edges) {
			int a = e[0], b = e[1];
			if (a > b) swap(a, b);
			cnt[a * 100000 + b]++;
			d[a]++, d[b]++;
		}

		vector<int> ds(d.begin() + 1, d.end());
		sort(ds.begin(), ds.end());

		vector<int> res;
		for (auto& q : queries) {
			int all = 0, s = 0;
			for (int i = 0, j = n - 1; i < j; j--) {
				while (i < j && ds[i] + ds[j] <= q) i++;
				if (i < j && ds[i] + ds[j] > q) all += j - i;
			}

			for (auto [k, v] : cnt) {
				int a = k / 100000, b = k % 100000;
				if (d[a] + d[b] > q && d[a] + d[b] - v <= q) s++;
			}

			res.push_back(all - s);
		}
		return res;
    }
};



