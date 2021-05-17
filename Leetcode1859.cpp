class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        unordered_map<int, string> mp;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            int j = i;
            while (j < n && s[j] != ' ') j++;
            string t = s.substr(i, j - i - 1);
            int idx = stoi(s.substr(j - 1, 1));
            mp[idx] = t;
            i = j - 1;
        }
        string res;
        for (int i = 1; mp.count(i) != 0; i++) {
            if (i != 1) res += " ";
            res += mp[i];
        }
        return res;
    }
};
