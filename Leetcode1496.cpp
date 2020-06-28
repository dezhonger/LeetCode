#include <map>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:

	struct hash_pair {
		template <class T1, class T2>
		size_t operator()(const pair<T1, T2>& p) const {
			auto hash1 = hash<T1>{}(p.first);
			auto hash2 = hash<T2>{}(p.second);
			return hash1 ^ hash2;
		}
	};

    bool isPathCrossing(string path) {
		unordered_set<pair<int, int>, hash_pair > su;
		su.insert(make_pair(0, 0));
		int x = 0, y = 0;
		for (char c: path) {
			if (c == 'N') y++;
			else if (c == 'S') y--;
			else if (c == 'E') x++;
			else x--;
			
			
			if (su.count(make_pair(x, y))) return true;
			su.insert(make_pair(x, y));
		}
		return false;
    }
};

int main() {
	Solution sol;
	cout << sol.isPathCrossing("NES") << endl;
	//cout << sol.isPathCrossing("NESWW") << endl;
	return 0;
}