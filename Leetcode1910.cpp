class Solution {
public:
    string removeOccurrences(string s, string t) {
        string ret;
        int m = t.size();
        for (auto& c : s) {
            ret += c;
            int len = ret.size();
            if (len >= m && ret.substr(len - m, m) == t) ret = ret.substr(0, len - m);
        }
        return ret;
    }
};
