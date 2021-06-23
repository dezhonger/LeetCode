class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for (int i = 0; i < n; i++) {
            int c;
            for (int j = 1; j <= 26; j++) {
                if (j + (n - i - 1) * 26 >= k) {
                    c = j;
                    break;
                }
            }
            res += (char)(c - 1 + 'a');
            k -= c;
        }
        return res;
    }
};
