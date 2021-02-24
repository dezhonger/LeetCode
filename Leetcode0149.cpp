#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcpde0149.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-02-24 23:09:04

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;

		int res = 0;
		for (auto& p : points) {
			int ss = 0;//重合的点
			int vs = 0;//和当前点横坐标相同的点，斜率无法表示
			unordered_map<LD, int> cnt;//保存斜率为key的点的数量
			for (auto& q: points) {
				if (p == q) ss++;
				else if (q[0] == p[0]) vs++;
				else {
					LD k = (LD)(q[1] - p[1]) / (q[0] - p[0]);
					cnt[k]++;
				}
			}
			int c = vs;
			for (auto [k, t]: cnt) c = max(t, c);
			res = max(res, c + ss);
		}
		return res;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

