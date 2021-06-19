class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> c(26);
            for (int j = i; j < n; j++) {
                c[s[j] - 'a']++;
                int a = 0, b = 1000;
                for (int k = 0; k < 26; k++) {
                    if (c[k] > 0) {
                        a = max(a, c[k]);
                        b = min(b, c[k]);
                    }
                }
                res += a - b;
            }

        }
        return res;
    }
};
