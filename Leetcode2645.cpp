class Solution {
public:
    int addMinimum(string s) {
        int t = 1;
        for (int i = 1; i < s.length(); ++i)
            t += s[i - 1] >= s[i]; // 必须生成一个新的 abc
        return t * 3 - s.length();
    }
};
