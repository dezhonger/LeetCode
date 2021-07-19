class Solution {
public:
    bool check(string s, set<char>& st) {
        for (char c : s) {
            if (st.count(c)) return false;
        }
        return true;
    }
    int canBeTypedWords(string t, string brokenLetters) {
        set<char> s(brokenLetters.begin(), brokenLetters.end());
        int n = t.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == ' ') continue;
            int j = i;
            while (j < n && t[j] != ' ') j++;
            string sub = t.substr(i, j - i);
            if (check(sub, s)) ans++;
            i = j - 1;
            
        }
        return ans;
    }
};
