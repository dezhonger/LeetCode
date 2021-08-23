class Solution {
public:
    inline int toInt(string& s) {
        int res = 0;
        for (char c :s) {
            res = res * 2 + c - '0';
        }
        return res;
    }
    inline string toString(int n, int x) {
        string res;
        while (x) {
            res = res + (char)(x % 2 + '0');
            x >>= 1;
        }
        int j = n - res.size();
        for (int i = 0; i < j; i++) res = res + '0';
        reverse(res.begin(), res.end());
        return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        int n = nums[0].size();
        for (string& s: nums) {
            st.insert(toInt(s));
        }
        for (int i = 0; i < (1 << n); i++) {
            if (!st.count(i)) return toString(n, i);
        }
        return "";
    }
};
