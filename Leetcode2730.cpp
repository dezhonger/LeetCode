class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 0, n = s.size(), c = 0;
        for (int l = 0, r = 1; l < n; l++)
        {
            if (c == 1)
            {
                while (r < n && s[r] != s[r - 1]) r++;
            }
            else if (c == 0)
            {
                while (r < n && s[r] != s[r - 1]) r++;
                if (s[r] == s[r - 1]) r++, c++;
                while (r < n && s[r] != s[r - 1]) r++;
            }

            res = max(res, r - l);

            if (s[l] == s[l + 1]) c--;
        }

        return res;
    }
};
