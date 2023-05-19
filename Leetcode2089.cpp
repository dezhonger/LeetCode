class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        int less = 0, equ = 0;
        for (int x: nums) {
            if (target > x) less++;
            else if (target == x) equ++;
        }

        if (equ == 0) return res;
        for (int i = less, j = 0; j < equ; i++, j++) res.push_back(i);
        return res;
    }
};
