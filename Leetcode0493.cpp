#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode493.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-02-22 23:31:18

class Solution {
public:
	vector<int> w;
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() - 1);
    }

	int merge(vector<int> &a, int l, int r) {
		if (l >= r) return 0;
		int mid = l + r >> 1;
		int ans = 0;
		ans += merge(a, l, mid);
		ans += merge(a, mid + 1, r);
		for (int i = l, j = mid + 1; i <= mid; i++) {
			while (j <= r && a[j] * 2ll < a[i]) j++;
			ans += j - (mid + 1);
		}
		w.clear();
		int i = l, j = mid + 1;
		while (i <= mid && j <= r) {
			if (a[i] <= a[j]) w.push_back(a[i++]);
			else w.push_back(a[j++]);
		}
		while (i <= mid) w.push_back(a[i++]);
		while (j <= r) w.push_back(a[j++]);
		for (int i = l, j = 0; j < w.size(); i++, j++) a[i] = w[j];
		return ans;
	}
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

