class Solution {
public:
    string mergeAlternately(string a, string b) {
        string res;
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            if (i < a.size()) res += a[i ++ ];
            if (j < b.size()) res += b[j ++ ];
        }
        return res;
    }
};
