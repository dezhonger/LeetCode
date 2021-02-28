class Solution {
public:
    int countMatches(vector<vector<string>>& items, string a, string b) {
        int res = 0, idx = 0;
        if (a == "color") idx = 1;
        else if (a == "name") idx = 2;
        for (auto s: items) res += s[idx] == b;
        return res;
    }
};