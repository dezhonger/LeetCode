class Solution {
public:
    int nextGreaterElement(int m) {
        string s = to_string(m);
        int n = s.size();

        int a = -1, b;
        for (int i = n - 1; i >= 1; i--) {
            if (s[i] > s[i - 1]) {
                a = i - 1;
                break;
            }
        }
        if (a == -1) return -1;
        for (int i = n - 1; i > a; i--) {
            if (s[i] > s[a]) {
                b = i;
                break;
            }
        }
        swap(s[a], s[b]);
        reverse(s.begin() + a + 1, s.end());
        LL res = stoll(s);
        if (res > INT_MAX) return -1;
        return res;
    }
};
