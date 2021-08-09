class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i++) {
            res += s[i];
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            if (j - i >= 2) res += s[i];
            i = j - 1;
        }
        return res;
    }
};
