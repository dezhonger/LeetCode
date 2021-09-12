typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

class Solution {
public:
    bool c(int v, string& s) {
      string s1;
      for (int i = 0; i < s.size(); i++) {
        if ((v >> i) & 1) s1 += s[i];
      }
      for (int i = 0, j = s1.size() - 1; i < j; i++, j--) {
        if (s1[i] != s1[j]) return false;
      }
      return true;
    }
    int maxProduct(string s) {
        int n = s.size(), ans = 0;
        int m = (1 << n);
        vector<bool> can(m);
        for (int i = 0; i < m; i++) if (c(i, s)) can[i] = true;
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < m; j++) {
            if ((i & j) == 0) {
              if (can[i] && can[j]) ans = max(ans, __builtin_popcount(i) * __builtin_popcount(j));
            }
          }
        }
        return ans;
    }    
};
