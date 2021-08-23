class Solution {
public:
    inline int cal(int x) {
        if (x < 0) x += 26;
        return x;
    }
    int minTimeToType(string word) {
        int res = 0;
        int pos = 0;
        for (char c: word) {
            res += min(cal(c - 'a' - pos), cal(pos - c + 'a'));
            pos = c - 'a';
            res++;
        }
        return res;
    }
};
