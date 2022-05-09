typedef long long LL;
int last[26][100010];
class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        int pos[26];
        memset(pos, -1, sizeof pos);
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            int l = pos[s[i] - 'a'];
            pos[s[i] - 'a'] = i;
            ans += 1LL * (i - l) * (n - i);
        }
        return ans;
    }
};
