class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals) {
        int mapping[26]{};
        iota(mapping, mapping + 26, 1); 
        for (int i = 0; i < chars.length(); ++i) mapping[chars[i] - 'a'] = vals[i];
        // 最大子段和（允许子数组为空）
        int ans = 0, f = 0;
        for (char c: s) {
            f = max(f, 0) + mapping[c - 'a'];
            ans = max(ans, f);
        }
        return ans;
    }
};
