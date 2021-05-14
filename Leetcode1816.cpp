class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size(), wc = 0;
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                res += s[i];
                continue;
            }
            int j = i;
            while (j < n && isalpha(s[j])) j++;
            string sub = s.substr(i, j - i);
            res += sub;
            wc++;
            if (wc == k) break;
            i = j - 1;
        }
        return res;
    }
};
