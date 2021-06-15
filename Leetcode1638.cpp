class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                int diff = 0;
                for (int k = 1; i + k <= s.size() && j + k <= t.size(); k++) {
                    if (s[i + k - 1] != t[j + k - 1]) diff++;
                    if (diff == 1) res++;
                    else if (diff > 1) break;
                }
            }
        }
        return res;
    }
};
 
