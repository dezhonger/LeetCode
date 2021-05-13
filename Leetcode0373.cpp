#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0373.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-14 03:18:11
//Last modified: 2021-05-14 03:28:57

struct Node {
    int s, a, b;
    bool operator> (const Node& w) const {
        return s > w.s;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node, vector<Node>, greater<Node>> q;
        for (int i = 0; i < nums1.size(); i++) {
            q.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> res;
        k = min(k, (int)nums1.size() * (int)nums2.size());
        while (k--) {
            Node node = q.top();
            q.pop();
            res.push_back({nums1[node.a], nums2[node.b]});
            if (node.b + 1 < nums2.size()) q.push({nums1[node.a] + nums2[node.b + 1], node.a, node.b +1});
        }
        return res;
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

