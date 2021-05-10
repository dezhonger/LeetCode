#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1834.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-11 02:19:09
//Last modified: 2021-05-11 03:02:30

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
const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int mod = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;

struct Node {
    int idx, a, b;
    bool operator< (const Node& w) const {
        if (b != w.b) return b > w.b;
        return idx > w.idx;
    }
};

class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            int n = tasks.size();
            vector<int> res;
            vector<pair<int, pair<int, int>>> p(n);
            for (int i = 0; i < n; i++) {
                auto x = tasks[i];
                p[i] = make_pair(x[0], make_pair(x[1], i));
            }
            sort(p.begin(), p.end());
            priority_queue<Node> q; 
            int j = 0;
            LL time = 1;
            while (1) {
                while (j < n && p[j].F <= time) {
                    q.push({p[j].S.S, p[j].F, p[j].S.F});
                    j++;
                }
                bool flag = false;
                if (q.empty()) {
                    flag = true;
                    //队列里没有任务
                    int k = j;
                    //当前时间没有一个任务可以进入队列，
                    while (k < n && p[k].F == p[j].F) {
                        q.push({p[k].S.S, p[k].F, p[k].S.F});
                        k++;
                    }
                    j = k;
                }
                Node cur = q.top();
                q.pop();
                res.push_back(cur.idx);
                int id = cur.idx;
                if (flag) time = tasks[id][0] + tasks[id][1];
                else time += tasks[id][1];

                if (res.size() == n) break;
            }
            return res;
        }
};



