class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        string res;
        for (int i = 0; i < w.size(); i++) {
            res += w[i];
            if (res.size() == s.size()) {
                return s == res;
            }
        }
        return false;
    }
};
