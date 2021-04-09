#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0818.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-09 22:23:27


struct Node {
	int pos, speed, step;
	bool operator< (const Node &w) const {
		return pos < w.pos;
	}
};

class Solution {
public:
	int t;	
	inline string concat(int a, int b) {
		string s = "";
		s += to_string(a);
		s += ',';
		s += to_string(b);
		return s;
	}

	int bfs() {
		unordered_set<string> s;
		queue<Node> q;
		q.push({0, 1, 0});
		s.insert(concat(0, 1));
		while (q.size()) {
			auto cur = q.front();
			q.pop();
			//cout << cur.pos << " " << cur.speed << " " << cur.step << endl;
			if (cur.pos > 2 * t || cur.pos < 0) continue;
			if (cur.pos == t) return cur.step;

			Node nxt = {cur.pos + cur.speed, cur.speed * 2, cur.step + 1};
			string s1 = concat(nxt.pos, nxt.speed);
			if (!s.count(s1)) {
				s.insert(s1);
				q.push(nxt);
			}

			if (cur.speed < 0) {
				Node n1 = {cur.pos, 1, cur.step + 1};
				string ns1 = concat(n1.pos, n1.speed);
				if (!s.count(ns1)) {
					s.insert(ns1);
					q.push(n1);
				}
			}
			if (cur.speed > 0) {
				Node n2 = {cur.pos, -1, cur.step + 1};
				string ns2 = concat(n2.pos, n2.speed);
				if (!s.count(ns2)) {
					s.insert(ns2);
					q.push(n2);
				}
			}
		}
		return -1;
	}

    int racecar(int target) {
		t = target;
        int ans = bfs();
		return ans;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
	Solution s;
	cout << s.racecar(3) << endl;
	cout << s.racecar(6) << endl;
	cout << s.racecar(15) << endl;
	cout << s.racecar(330) << endl;
	cout << s.racecar(432) << endl;
	cout << s.racecar(8861) << endl;
	cout << s.racecar(6102) << endl;
	return 0;
}

