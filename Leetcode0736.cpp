#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0736.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-18 03:03:07

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
		typedef unordered_map<string, int> mmp;

		int evaluate(string expression) {
			int k = 0;
			return dfs(expression, k, mmp());
		}

		int get_value(string& str, int& k, mmp mp) {
			int value;
			if (str[k] == '-' || isdigit(str[k])) {
				int i = k + 1;
				while (isdigit(str[i])) i++;
				value = stoi(str.substr(k, i - k));
				k = i;
			} else if (str[k] != '(') {
				string name;
				while (str[k] != ' ' && str[k] != ')') name += str[k++];
				value = mp[name];
			} else {
				value = dfs(str, k, mp);
			}
			return value;
		}

		int dfs(string& str, int& k, mmp mp) {
			int value;
			k++; // skip '('
			string type = str.substr(k, 3);
			if (type == "let") {
				k += 4; //skip "let "
				while (str[k] != ')') {
					if (str[k] == '(' || str[k] == '-' || isdigit(str[k])) {
						value = get_value(str, k, mp);
						break;
					}
					string name;
					while (str[k] != ' ' && str[k] != ')') name += str[k++];
					if (str[k] == ')') {
						value = mp[name];
						break;
					}
					k++; //skip ' '
					mp[name] = get_value(str, k, mp);
					k++; //skip ' '
				}
			} else if (type == "add") {
				k += 4; //skip "add "
				int a = get_value(str, k, mp);
				k++;
				int b = get_value(str, k, mp);
				value = a + b;
			} else {
				k += 5;
				int a = get_value(str, k, mp);
				k++;
				int b = get_value(str, k, mp);
				value = a * b;
			}
			k++; //skip ')'
			return value;
		}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

