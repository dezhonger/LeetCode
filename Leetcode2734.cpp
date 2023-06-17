class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        int i = 0, j;
        while (i < n && s[i] == 'a') i++;
        if (i == n)
        {
            s.back() = 'z';
            return s;
        }

        j = i;
        while (j < n && s[j] != 'a') j++;
        for (int k = i; k < j; k++) s[k]--;
        return s;
    }
};
