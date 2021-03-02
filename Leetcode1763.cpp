class Solution {
public:
    string longestNiceSubstring(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            int a = 0, b = 0;
            string t = "";
            for (int j = i; j < s.size(); j++) {
                if (s[j] >= 'a' && s[j] <= 'z') a |= 1 << (s[j] - 'a');
                else b |= 1 << (s[j] - 'A');
                t += s[j];
                if (a == b && t.size() > res.size()) res = t;
            }
            
        }
        return res;
    }
};
