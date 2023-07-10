class Solution {
public:
    string robotWithString(string s) {
        string ans;
        int cnt[26]{}, min = 0; // min 表示剩余最小字母
        for (char c : s) ++cnt[c - 'a'];
        stack<char> st;
        for (char c : s) {
            --cnt[c - 'a'];
            while (min < 25 && cnt[min] == 0) ++min;
            st.push(c);
            while (!st.empty() && st.top() - 'a' <= min) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};
