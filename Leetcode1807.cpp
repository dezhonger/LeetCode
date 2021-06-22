class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto k: knowledge) mp[k[0]] = k[1];
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int j = i + 1;
                while (j < n && s[j] != ')') j++;
                string sb = s.substr(i + 1, j - i - 1);
                if (mp.count(sb)) sb = mp[sb];
                else sb = "?";
                res += sb;
                i = j;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
