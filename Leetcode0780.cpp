#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0780.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-12 01:00:27

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

typedef long long LL;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (tx >= sx && ty >= sy) {
			if (tx == sx && ty == sy) return 1;
			if (tx < sx || ty < sy) return 0;
			if (tx > ty) {
				if (ty > sy) tx %= ty;
                else if (ty == sy) return (tx - sx) % sy == 0;
			} else {
				if (tx > sx) ty %= tx;
                else if (tx == sx) return (ty - sy) % sx == 0;
			}
		}
        return 0;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

