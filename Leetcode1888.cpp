const int N = 100005;
int l[N][2], r[N][2];
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = ' ' + s;
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        for (int i = 1, j = n; i <= n; i++, j--) {
            l[i][0] = l[i - 1][1] + ('0' != s[i]);
            l[i][1] = l[i - 1][0] + ('1' != s[i]);
            r[j][0] = r[j + 1][1] + ('0' != s[j]);
            r[j][1] = r[j + 1][0] + ('1' != s[j]);
        }

        int ans = INT_MAX;
        ans = min(l[n][0], l[n][1]);
        if (n & 1) {
            for (int i = 1; i < n; i++) {
                ans = min(ans, (s[i] != '1') + (s[i + 1] != '1') + l[i - 1][0] + r[i + 2][0]);
                ans = min(ans, (s[i] != '0') + (s[i + 1] != '0') + l[i - 1][1] + r[i + 2][1]);
            }
        }
        
        return ans;

    }
};
