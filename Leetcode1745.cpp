#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
bool f[N][N];
bool g[N];
class Solution {
public:
    bool checkPartitioning(string s) {
		int sz = s.size();
        s = ' ' + s;
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		for (int i = 1; i <= sz; i++) {
			int l = i - 1, r = i + 1;
			f[i][i] = true;
			while (l >= 1 && r <= sz && s[l] == s[r]) {
				f[l--][r++] = true;
			}
		}
		for (int i = 2; i <= sz; i++) {
			int l = i - 1, r = i;
			while (l >= 1 && r <= sz && s[l] == s[r]) {
				f[l--][r++] = true;
			}
		}

		
		for (int i = 1; i <= sz; i++) {
			for (int j = sz; j >= i; j--) {
				if (f[1][i] && f[j][sz] && (j - 1) >= (i + 1) && f[i + 1][j - 1]) return true;
			}
		}

		return false;
    }
};

int main() {
	Solution s;
	cout << s.checkPartitioning("acab") << endl;
	cout << s.checkPartitioning("abcbdd") << endl;
	cout << s.checkPartitioning("bcbddxy") << endl;
	cout << s.checkPartitioning("bcbddxy") << endl;
	return 0;
}


