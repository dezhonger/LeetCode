class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int last = 0;
        for (int x: target) {
            if (x >= last) ans += x - last, last = x;
            else last = x;
        }
        return ans;
    }
};