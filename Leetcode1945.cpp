
class Solution {
public:
    string cal(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) res += s[i] - '0';
        return to_string(res);
    }
    int getLucky(string s, int k) {
        int res = 0;
        string ss;
        for (int i = 0; i < s.size(); i++) ss += to_string(s[i] - 'a' + 1);
        while (k--) {
            ss = cal(ss);
        }
        return stoi(ss);
    }
};
