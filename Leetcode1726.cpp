class Solution {
public:
    int tupleSameProduct(vector<int>& a) {
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                mp[a[i] * a[j]]++;
            }
        }
        int res = 0;
        for (auto [k, v]: mp) res += v * (v - 1) * 4;
        return res;
    }
};
 
