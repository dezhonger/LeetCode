#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0488.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-19 01:46:32

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;

#define Debug(x) cout<<#x<<"="<<x<<endl;

class Solution {
public:
	//达到这个状态的最少步数
        unordered_map<string, int> f; //记忆化搜索
        unordered_map<char, int> cnt; //每种字符的数量
	int ans = 6;

	inline string cleanup(string s) {
		bool change = true;
		while (change) {
			change = false;
			for (int i = 0; i < s.size(); i++) {
				int j = i + 1;
				while (j < s.size() && s[j] == s[i]) j++;
				if (j - i >= 3) {
					s = s.substr(0, i) + s.substr(j);
					change = true;
					break;
				}
			}
		}
		return s;
	}

	inline string get() {
		string s;
		for (auto [x, c]: cnt) s += to_string(c);
		return s;
	}

    int h(string board) {  // 至少还需要多少次操作
        sort(board.begin(), board.end());
        int res = 0;
        for (int i = 0; i < board.size();) {
            int j = i + 1;
            while (j < board.size() && board[j] == board[i]) j ++ ;
            if (j - i + cnt[board[i]] < 3) return 6;
            if (j - i <= 2) res += 3 - (j - i);
            i = j;
        }
        return res;
    }

	void dfs(string board, string hand) {
		if (f[board + ' ' + hand] + h(board) >= ans) return ;
		for (auto [x, c]: cnt) {
			if (c > 0) {
				cnt[x]--;
				for (int i = 0; i <= board.size(); i++) {
					auto r = cleanup(board.substr(0, i) + x + board.substr(i));
					auto s = r + ' ' + get();
					if (f.count(s) == 0 || f[s] > f[board + ' ' + hand] + 1) {
						f[s] = f[board + ' ' + hand] + 1;
						if (r.empty()) ans = min(ans, f[s]);
						dfs(r, get());
					}
				}
				cnt[x]++;
			}
		}
	}

    int findMinStep(string board, string hand) {
		for (auto c : hand) cnt[c]++;
		f[board + ' ' + hand] = 0;
		dfs(board, get());
		if (ans == 6) return -1;
		return ans;
    }
};

