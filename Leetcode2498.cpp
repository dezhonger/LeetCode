class Solution {
public:
    int maxJump(vector<int>& s) {
        int res = s[1] - s[0];
        for (int i = 2; i < s.size(); i++) res = max(res, s[i] - s[i - 2]);
        return res;
    }
};
