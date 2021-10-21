class Solution {
public:
    bool winnerOfGame(string s) {
        int c[2] = {0}, n = s.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            if (j - i >= 3) c[s[i] - 'A'] += j - i - 2;
            i = j - 1;
        }
        return c[0] >= c[1] + 1;
    }
};
