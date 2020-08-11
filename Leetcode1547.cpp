#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
	int dp[105][105] = {};
	
    int minCost(int n, vector<int>& cuts) {
		vector<int> v;
		v.push_back(0);
		v.insert(v.end(), cuts.begin(), cuts.end());
		v.push_back(n);
		sort(v.begin(),v.end());
		for (auto x : v) cout << x << " ";
		cout << endl;
		int le = v.size();
		//ans = dp[0][le-1]
		for (int i = 1; i < le; i++) dp[i - 1][i] = 0;
		for (int len = 2; len < le; len++) {
			for (int i = 0; i + len < le; i++) {
				int j = i + len;
				int start = v[i];
				int end = v[j];
				dp[i][j] = 10000000;
				int cost = end - start;
				for (int k = i + 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cost);
				
			}
		}
		return dp[0][le - 1];
    }
};

int main() {
	vector<int> v2 = {1,3,4,5};
	vector<int> v1 = {5,6,1,4,2};
	Solution s;
	cout << s.minCost(7, v2) << endl;
	cout << s.minCost(9, v1) << endl;
	return 0;
}