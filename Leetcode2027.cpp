class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size(), t = 0;
        for (int i = 0; i < n;) {
            if (s[i] == 'X') t++, i += 3;
            else i++;
        }
        return t;
    }
};
