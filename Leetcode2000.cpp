class Solution {
public:
    string reversePrefix(string w, char ch) {
        int n = w.size();
        int j = 0;
        while (j < n && w[j] != ch) j++;
        string ans;
        if (j < n && w[j] == ch) {
            for (int i = j; i >= 0; i--) ans += w[i];
            for (int i = j + 1; i < n; i++) ans += w[i];
        } else {
            ans = w;
        }
        return ans;
    }
};
