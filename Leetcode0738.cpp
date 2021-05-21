class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int m = s.size(), mark = m;
        for (int i = m - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                mark = i;
            }
        }
        for (int i = mark; i < m; i++) s[i] = '9';
        int res = 0;
        for (int i = 0; i < m; i++) res = res * 10 + s[i] - '0';
        return res;
    }
};
