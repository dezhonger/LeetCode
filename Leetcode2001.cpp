typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
class Solution {
public:

    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        const int N = 100010;
        unordered_map<int, int> um;
        for (auto& e: rectangles) {
          int d = gcd(e[0], e[1]);
          e[0] /= d, e[1] /= d;
          um[1LL * e[0] * N + e[1]]++;
        }
        LL ans = 0;
        for (auto& [k, v]: um) ans += 1LL * v * (v - 1) / 2;
        return ans;
    }
};
