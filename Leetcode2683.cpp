class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> a(n), b(n);
        for (int i = 1; i < n; i++) a[i] = a[i - 1] ^ derived[i - 1];
        if (a[0] ^ a.back() == derived.back()) return true;

        // b[0] = 1;
        // for (int i = 1; i < n; i++) b[i] = b[i - 1] ^ derived[i - 1];
        // if (b[0] ^ b.back() == derived.back()) return true;
        
        return false;
    }
};

// https://leetcode.cn/problems/neighboring-bitwise-xor/solution/tui-gong-shi-by-endlesscheng-90t5/ 简单解法
