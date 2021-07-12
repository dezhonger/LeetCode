class Solution {
public:
    int cal(string& s, int x) {
        int n = s.size();
        int l = 0;
        while (l < n && s[l] - 'a' != x) l++;
        if (l >= n - 2) return 0;
        int r = n - 1;
        while (r > l && s[r] - 'a' != x) r--;
        if (l >= r) return 0;
        unordered_set<char> st;
        for (int i = l + 1; i < r; i++) st.insert(s[i]);
        return st.size();
        
    }
    int countPalindromicSubsequence(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < 26; i++) {
            res += cal(s, i);
        }
        return res;
    }
};
