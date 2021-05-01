#include <bits/stdc++.h>
using namespace std;
//Filename: 5733.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-01 23:20:23
//Last modified: 2021-05-02 00:17:42

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
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
		int n = rooms.size(), m = queries.size();
		vector<int> ans(m, -1);
		set<int> s;
		for (int i = 0; i < n; i++) swap(rooms[i][0], rooms[i][1]);
		sort(rooms.begin(), rooms.end());
		reverse(rooms.begin(), rooms.end());
		for (int i = 0; i < m; i++) {
			swap(queries[i][0], queries[i][1]);
			queries[i].pb(i);
		}
		sort(queries.begin(), queries.end());
		reverse(queries.begin(), queries.end());
		for (int i = 0, j = 0; i < m; i++) {
			int id = queries[i][2];
			while (j < n && rooms[j][0] >= queries[i][0]) s.insert(rooms[j++][1]);
			auto it = s.lower_bound(queries[i][1]);
			if (it != s.end()) ans[id] = *it;
			if (it != s.begin()) {
				it--;
				if (ans[id] == -1 || ans[id] - queries[i][1] >= queries[i][1] - *it) ans[id] = *it;
			}
		}
		return ans;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

