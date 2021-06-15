class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size(), false);
        for (int i = 0; i < l.size(); i++) {
            int len = r[i] - l[i] + 1;
            if (len == 1) continue;
            int maxV = *(max_element(nums.begin() + l[i], nums.begin() + r[i] + 1));
            int minV = *(min_element(nums.begin() + l[i], nums.begin() + r[i] + 1));
            if (maxV == minV) {
                res[i] = true;
                continue;
            }
            if ((maxV - minV) % (len - 1) != 0) {
                continue;
            }
            int d = (maxV - minV) / (len - 1);
            unordered_set<int> s(nums.begin() + l[i], nums.begin() + r[i] + 1);
            bool f = true;
            for (int i = 0, c = minV; i < len - 1; i++) {
                c += d;
                if (!s.count(c)) {
                    f = false;
                    break;
                }
            }
            res[i] = f;

        }
        return res;
    }
};
 
