class Solution {
public:
    bool check(string& s, string& t, int k) {
        int pos = 0, m = t.size();
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == t[pos % m]) pos++;
        }
        return pos >= k * m;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        // tips:字符串的长度<=7
        vector<vector<string>> vs(8);
        vs[0] = {""};
        for (int i = 0; i < 8; i++) {
            for (string& t: vs[i]) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string tt = t + c;
                    if (check(s, tt, k)) vs[i + 1].push_back(tt);
                }
            }
        }
        for (int i = 7; i >= 0; i--) {
            if (!vs[i].empty()) return vs[i].back();
        }
        return "";
    }
};
