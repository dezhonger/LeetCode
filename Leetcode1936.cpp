class Solution {
public:
    int addRungs(vector<int>& r, int dist) {
        int ans = 0, last = 0;
        for (int i = 0; i < r.size(); i++) {
            int len = r[i] - last;
            int need = (len + dist - 1) / dist;
            ans += max(0, need - 1);
            last = r[i];
        }
        return ans;
    }
};
