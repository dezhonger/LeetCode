class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        long long a = 0, b = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            char c = text[i];
            if (c == pattern[1]) b++, s += a;
            if (c == pattern[0]) a++;
            
        }

        return s + max(a, b);
    }
};
