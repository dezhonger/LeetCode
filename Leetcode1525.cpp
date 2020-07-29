#include <bits/stdc++.h>
using namespace std;

class Solution {
	
public:
	int c1[26], c2[26];
    int numSplits(string s) {
		int ans = 0;
        set<char> s1, s2;
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for (int c : s) {
			c2[c - 'a']++;
			s2.insert(c);
		}
		cout << s2.size() <<endl;
		for (char c : s) {
			c1[c - 'a']++;
			if (c1[c - 'a'] == 1) s1.insert(c);
			
			c2[c - 'a']--;
			if (c2[c - 'a'] == 0) s2.erase(c);
			
			
			if (s1.size() == s2.size()) ans++;
		}
		return ans;
		
    }
	
	
};

int main() {
	Solution s;

	cout << s.numSplits("aacaba") << endl;
	return 0;
}