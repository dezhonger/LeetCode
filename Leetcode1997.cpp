  
typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

//https://leetcode-cn.com/problems/first-day-where-you-have-been-in-all-the-rooms/solution/javascript-dong-tai-gui-hua-by-zw-l-hl6l/
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        // f[i] 第一次访问i房间的时间
        int n = nextVisit.size();
        vector<int> f(n);
        f[0] = 0;
        for (int i = 1; i < n; i++) {
            // 第一次访问i：为第一次访问i-1，然后跳到nextVisit[i-1]，然后在第二次访问i-1，然后再访问1步到达i
            // 根据f的定义： 第三次访问nextVisit[i-1]，然后再重新访问到房间i-1，的天数为f[i - 1] - f[nextVisit[i - 1]]
            f[i] = f[i - 1] + 1 + f[i - 1] - f[nextVisit[i - 1]] + 1;
            f[i] = (f[i] + mod) % mod;
        }
        return f[n - 1];
    }
};
