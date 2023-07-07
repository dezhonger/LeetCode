class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size();

        string ss = s, tt = t;
        ss.erase(remove(ss.begin(), ss.end(), '_'), ss.end());
        tt.erase(remove(tt.begin(), tt.end(), '_'), tt.end());
        if (ss != tt) return false;

        for (int i = 0, j = 0; i < n; i++)
        {
            if (s[i] == '_') continue;
            while (t[j] == '_') j++;
            if (j >= n) return false;
            if (s[i] != t[j]) return false;
            if (s[i] == 'L' && i < j) return false;
            if (s[i] == 'R' && i > j) return false;
            j++;
        }
        return true;
    }
};
