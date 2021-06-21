class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), j = -1;
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') & 1) {
                j = i;
                break;
            }
        }
        if (j == -1) return "";
        return num.substr(0, j + 1);
    }
};
