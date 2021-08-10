class Solution {
public:
    int minSwaps(string s) {
        int res = 0, mv = 0;
        for (char c : s) {
            if (c == '[') res++;
            else res--;
            mv = min(mv, res);
        }
        return (-mv + 1) / 2;
    }
};
