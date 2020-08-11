#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
	char find(int n, int k) {
		int len = (1 << n) - 1;
		if (k == len / 2) return n == 1 ? '0' : '1';
		if (k < len / 2) return find(n - 1, k);
		return '0' + '1' - find(n - 1, len - 1 - k);
	}

    char findKthBit(int n, int k) {
		return find(n, k - 1);
    }
};