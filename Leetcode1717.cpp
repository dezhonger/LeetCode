class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                if (x <= y && st.size() && st.top() == 'b') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else if (s[i] == 'b'){
                if (x >= y && st.size() && st.top() == 'a') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }
        vector<char> v;
        while (st.size()) v.push_back(st.top()), st.pop();
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 'a') {
                if (st.size() && st.top() == 'b') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(v[i]);
                }
            } else if (v[i] == 'b') {
                if (st.size() && st.top() == 'a') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(v[i]);
                }
            } else {
                st.push(v[i]);
            }
        }

        return ans;
    }
};
