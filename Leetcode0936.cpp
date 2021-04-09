#include <bits/stdc++.h>
using namespace std;
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;

class Solution {
public:
	
	bool check(string s, string t) {
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (t[i] == '?') continue;
			if (s[i] != t[i]) return false;
		}
		return true;
	}

    vector<int> movesToStamp(string stamp, string target) {
        	queue<int> q;
		set<int> use;

		int n = stamp.size(), m = target.size();
		for (int i = 0; i + n - 1 < m; i++) {
			if (stamp == target.substr(i, n)) q.push(i), use.insert(i);
		}
		vector<int> ans;
		//cout << q.size() << endl;

		while (q.size()) {
			int cur = q.front();
			q.pop();
			for (int i = cur; i <= cur + n - 1; i++) target[i] = '?';
			ans.push_back(cur);
			for (int i = max(0, cur - n + 1); i <= min(m - n, cur + n - 1); i++) {
				if (check(stamp, target.substr(i, n)) && !use.count(i)) {
					use.insert(i);
					q.push(i);
				}
			}
		}
		for (int i = 0; i < m; i++) if (target[i] != '?') return vector<int>();
		reverse(ans.begin(), ans.end());
		return ans;
    }
};


int main() {
	Solution s;
	auto ans = s.movesToStamp("abc", "ababc");
	//auto ans = s.movesToStamp("abca", "aabcaca");
	//for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	each(ans, it);

	return 0;
}
