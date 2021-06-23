class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int a = 0, b = 0, n = encoded.size();
        vector<int> res(n + 1);
        for (int i = 1; i <= n + 1; i++) b ^= i;
        for (int i = 1; i < n; i += 2) a ^= encoded[i];
        res[0] = a ^ b;
        for (int i = 1; i <= n; i++) res[i] = encoded[i - 1] ^ res[i - 1];
        return res;
    }
};
