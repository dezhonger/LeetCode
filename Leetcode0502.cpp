#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0502.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-03-31 20:45:55
class Solution {
public:

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> projs(n);

        for (int i = 0; i < n; i++)
            projs[i] = make_pair(Capital[i], Profits[i]);

        sort(projs.begin(), projs.end());

        priority_queue<int> heap; 

        int i = 0;
        while (k--) {
            while (i < n && W >= projs[i].first) {
                heap.push(projs[i].second);
                i++;
            }

            if (!heap.empty()) {
                W += heap.top();
                heap.pop();
            }
        }
        return W;
    }
};



int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

