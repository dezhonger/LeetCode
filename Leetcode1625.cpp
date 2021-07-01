class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        set<string> st;
        st.insert(s);
        int n = s.size();
        queue<string> q;
        q.push(s);
        while (q.size()) {
            string cur = q.front();
            if (cur < res) res = cur;
            q.pop();
            string nxt = cur.substr(n - b) + cur.substr(0, n - b);
            if (!st.count(nxt)) q.push(nxt), st.insert(nxt);
            for (int i = 1; i < n; i += 2) {
                cur[i] = (cur[i] - '0' + a) % 10 + '0';
            }
            if (!st.count(cur)) q.push(cur), st.insert(cur);
        }
        return res;
    }
};
