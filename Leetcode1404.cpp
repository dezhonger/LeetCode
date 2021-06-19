class Solution {
public:
    int numSteps(string s) {
        int c = 0, n = s.size(), res = 0;
        for (int i = n - 1; i > 0; i--) {
            if (c == 0) {
                if (s[i] == '0') res++;
                else res += 2, c = 1;
            } else {
                if (s[i] == '0') res += 2, c = 1;
                else res++, c = 1;
            }
        }
        res += c;
        return res;
    }
};
 
