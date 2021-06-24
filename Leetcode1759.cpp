
typedef long long LL;
LL mod = (int)1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        LL res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            res += 1LL * (len + 1) * len / 2;
            res %= mod;
            i = j - 1;
        }
        return res;
    }
};
