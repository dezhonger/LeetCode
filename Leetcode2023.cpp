class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0, m = target.size();
        unordered_map<string, int> mp;
        for (auto& s: nums) mp[s]++;
        for (int i = 1; i < m; i++) {
            string a = target.substr(0, i);
            string b = target.substr(i, m - i);
            if (mp[a]) {
                if (a != b) ans += mp[a] * mp[b];
                else ans += mp[a] * (mp[a] - 1);
            }
        }
        return ans;
        
    }
};
