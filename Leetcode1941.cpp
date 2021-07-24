class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>  c(26, 0);
        for (char x : s) c[x - 'a']++;
        set<int> st;
        for (int i = 0; i < 26; i++) {
            if (c[i]) st.insert(c[i]);
        }
        return st.size() == 1;
    }
};
