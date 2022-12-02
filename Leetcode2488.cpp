class Solution {
public:
    int countSubarrays(vector<int>& n, int k) {
        unordered_map<int, int> cnt;
        int p = find(n.begin(), n.end(), k) - n.begin();
        int res = 0;
        for (int i = p, v = 0; i < n.size(); i++) {
            v += n[i] == k ? 0 : n[i] < k ? -1 : 1;
            cnt[v]++;
        }
        for (int i = p, v = 0; i >= 0; i--) {
            v += n[i] == k ? 0 : n[i] < k ? -1 : 1;
            res += cnt[-v] + cnt[-v + 1];
        }
        return res;
    }
};
