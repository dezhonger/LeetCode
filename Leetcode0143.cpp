#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0143.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-06 04:53:26
//Last modified: 2021-05-06 05:16:19

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
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        void reorderList(ListNode* head) {
            if (head == NULL) return ;
            int n = 1;
            auto h = head;
            while (h -> next != NULL) {
                n++;
                h = h -> next;
            }
            if (n == 1) return ;
            int m = (n + 1) / 2;
            h = head;
            for (int i = 1; i < m; i++) {
                h = h -> next;
            }

            //翻转h后的链表
            auto p = h -> next;
            while (p -> next != NULL) {
                auto q = p -> next;
                p -> next = q -> next;
                q -> next = h -> next;
                h -> next = q;
            }



            auto h1 = head, h2 = h -> next, tail1 = h;

            while (h1 -> next != h2) {
                auto h11 = h1 -> next, h22 = h2 -> next;
                //cout << h11 -> val << " " << h22 -> val << endl;
                tail1 -> next = h2 -> next;
                h2 -> next = h1 -> next;

                h1 -> next = h2;
                h1 = h11, h2 = h22;
            }
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

