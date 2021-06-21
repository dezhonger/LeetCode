class Solution {
public:
    int len;
    int get(int x)
    {
        return x / len;
    }
    

    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n);
        len = (int)sqrt(nums.size());
        for (int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [&](const vector<int>& a, const vector<int>& b){
            int i = get(a[0]), j = get(b[0]);
            if (i != j) return i < j;
            return a[1] < b[1];
        });
        vector<int> cnt(101);
        for (int k = 0, i = -1, j = 0; k < n; k++) {
            int id = queries[k][2], l = queries[k][0], r = queries[k][1];
            while (i < r) cnt[nums[++i]]++;
            while (i > r) cnt[nums[i--]]--;
            while (j < l) cnt[nums[j++]]--;
            while (j > l) cnt[nums[--j]]++;
            int pre = -1, ans = INT_MAX;
            for (int z = 1; z <= 100; z++) {
                if (cnt[z] == 0) continue;
                if (pre != -1) ans = min(ans, z - pre);
                pre = z;
            }
            if (ans == INT_MAX) ans = -1;
            res[id] = ans;
        }

        return res;
    }
};
