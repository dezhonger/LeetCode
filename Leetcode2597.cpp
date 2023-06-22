class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        unordered_map<int, map<int, int>> groups;
        for (int x : nums) ++groups[x % k][x];
            
        int ans = 1;
        for (auto&[_, g]: groups) {
            int m = g.size(), f[m + 1];
            auto it = g.begin();
            f[0] = 1;
            f[1] = 1 << it++->second;
            for (int i = 2; it != g.end(); ++it, ++i)
                if (it->first - prev(it)->first == k)
                    f[i] = f[i - 1] + f[i - 2] * ((1 << it->second) - 1);
                else
                    f[i] = f[i - 1] << it->second;
            ans *= f[m];
        }
        return ans - 1; // -1 去掉空集
    }
};
