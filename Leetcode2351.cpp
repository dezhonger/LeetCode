class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for (char c : s)
        {
            if (v[c - 'a'] == 1) return c;
            v[c - 'a']++;
        }
        return 'a';
    }
};
