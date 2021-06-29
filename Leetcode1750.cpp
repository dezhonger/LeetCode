class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), i = 0, j = n - 1, t;
        while (i < j && s[i] == s[j]) {
            t = i;
            while (t < j && s[t] == s[i]) t++;
            i = t - 1;
            t = j;
            while (t > i && s[t] == s[j]) t--;
            j = t + 1;
            i++, j--;
        }
        return j - i + 1;
    }
};
