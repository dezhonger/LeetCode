class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int r = 0; //can make [0, r]
        for (int x : coins) {
            //x can make [x, x + r]
            if (x <= r + 1) {
                //can make [0, x + r]
                r += x;
            } else {
                return r + 1; //[0, r] has r + 1 numbers;
            }
        }
        return r + 1; //[0, r] has r + 1 numbers;
    }
};
