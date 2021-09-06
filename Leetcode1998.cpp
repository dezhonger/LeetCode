int f[100010], cnt[100010];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = find(y);
}
class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) cnt[x] = 1;
        for (int i = 1; i <= 100000; i++) f[i] = i;
        for (int i = 2; i <= 100000; i++) {
            if (1) {
                for (int j = i + i; j <= 100000; j += i) {
                    if (cnt[j]) merge(i, j);
                }
            }
        }
        // debug(a);
        for (int i = 0; i < n; i++) {
            // debug(i, nums[i], a[i], find(nums[i]), find(a[i]));
            if (find(nums[i]) != find(a[i])) return false;
        }
        return true;
    }
};
