#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0782.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-12 00:25:46

#define reps(i, a, b) for(int i = (a); i < (b); i++)
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
//行列交换是不会改变原有行的种类的，列也如此.
//充分必要条件:行只有两种，列也只有两种。分别单独考虑把行变为0101010...或101010...取最小值，列也如此。
class Solution {
	public:
		int MAXV = 1e8, n;

		int get(int a) {
			int ans = 0;
			while (a) {
				if (a & 1) ans++;
				a >>= 1;
			}
			return ans;
		}

		int get(int a, int b) {
			if (get(a) != get(b)) return MAXV;
			int c = a ^ b;
			return get(c) / 2;
		}

		int movesToChessboard(vector<vector<int>>& board) {
			set<int> rs, cs;
			rs.clear();
			cs.clear();
			n = board.size();
			for (int i = 0; i < n; i++) {
				int r = 0, c = 0;
				for (int j = 0; j < n; j++) {
                    r = (r << 1) | board[i][j];
                    c = (c << 1) | board[j][i];
					
				}
				rs.insert(r), cs.insert(c);
			}
			if (rs.size() != 2 || cs.size() != 2) return -1;
			int r1 = *rs.begin(), r2 = *rs.rbegin();
			if ((r1 ^ r2) != (1 << n) - 1) return -1;
			int c1 = *cs.begin(), c2 = *cs.rbegin();
			if ((c1 ^ c2) != (1 << n) - 1) return -1;

			int t1 = 0, t2 = 0;
			for (int i = 0; i < n; i++) {
				if (i & 1) t1 |= (1 << i);
				else t2 |= (1 << i);
			}
			
			int rans = min(get(r1, t1), get(r1, t2));
			int cans = min(get(c1, t1), get(c1, t2));
			int ans = rans + cans;

			if (ans >= MAXV) return -1;
			return ans;
		}
};


int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

