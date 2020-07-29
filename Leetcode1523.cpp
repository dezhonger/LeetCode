#include <bits/stdc++.h>
using namespace std;

class Solution {
	
public:
	int f(int x) {
		return (x + 1) / 2;
	}
    int countOdds(int low, int high) {
        return f(high) - f(low - 1);
    }
};

int main() {
	Solution s;
	cout << s.countOdds(3, 7) << endl;
	cout << s.countOdds(8, 10) << endl;
	return 0;
}