#include <bits/stdc++.h>
using namespace std;

class Solution {
	
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1;
		int ans = 0, s = 0;
		cout << ans << endl;
		for (int x : arr) {
			s += x;
			if (s & 1) ans += even, odd++;
			else ans += odd, even++;
			s %= 2;
		}
		cout << ans << endl;
		return ans;
    }
	
	
};

int main() {
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	cout << s.numOfSubarrays(v) << endl;
	return 0;
}