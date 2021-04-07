#include <bits/stdc++.h>
using namespace std;



const int N = 510;
vector<int> g[N];

set<int> ss;
struct Node {
    int pos, step;
};

class Solution {
public:


    bool can(vector<vector<int>>& routes, int i, int j) {
        auto x = routes[i];
        auto y = routes[j];
        int n1 = x.size(), n2 = y.size();
        int a = 0, b = 0;
        
        while (a < n1 && b < n2) {
            if (x[a] == y[b]) return true;
            if (x[a] < y[b]) a++;
            else b++;
        }
        return false;

    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        bool v[N];
        set<int> mp[N];
        memset(v, 0, sizeof v);
        memset(g, 0, sizeof g);
        ss.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (can(routes, i, j)) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int x : routes[i]) {
                 mp[i].insert(x);
                 if (x == source) ss.insert(i);
            }
        }
        

        
        //if (mp[source].size() == 0 || mp[target].size() == 0) return -1;
        queue<Node> q;
        for (int x : ss) {
            q.push({x, 1});
            v[x] = true;
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            //cout << t.pos << endl;
            if (mp[t.pos].find(target) != mp[t.pos].end()) return t.step;
            for (auto x : g[t.pos]) {
                if (!v[x]) {
                    q.push({x, t.step + 1});
                    v[x] = true;
                }
            }
        }
        return -1;
    }
};



int main() {
    return 0;
}