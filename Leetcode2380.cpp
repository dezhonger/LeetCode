// https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string/solution/by-endlesscheng-pq2x/
// https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string/solution/by-newhar-o6a1/
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res = 0;
        for(int i = 0, cnt = 0; i < s.size(); ++i) {
            if(s[i] == '0') ++cnt;
            else if(cnt > 0) res = max(res + 1, cnt);
        }
        return res;
    }
};
