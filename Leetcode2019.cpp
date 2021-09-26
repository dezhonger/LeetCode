class Solution {
public:

    // 这里是LC227的代码
    #define start 227
    stack<int> num;
    stack<char> op;

    void eval() {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int r;
        if (c == '+') r = a + b;
        else if (c == '-') r = a - b;
        else if (c == '*') r = a * b;
        else r = a / b;
        num.push(r);
    }

    int calculate(string s) {
        unordered_map<char, int> pr;
        pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
        for (int i = 0; i < s.size(); i ++ ) {
            char c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j ++ ] - '0');
                num.push(x);
                i = j - 1;
            } else {
                while (op.size() && pr[op.top()] >= pr[c]) eval();
                op.push(c);
            }
        }
        while (op.size()) eval();
        return num.top();
    }
    #define end 227

    int scoreOfStudents(string s, vector<int>& answers) {
        vector<int> cnt(1010);
        for (auto x: answers) cnt[x]++;
        
        int rightValue = calculate(s);
        int len = s.size(), ans = 5 * cnt[rightValue];
        vector<vector<unordered_set<int>>> dp(len + 2, vector<unordered_set<int>>(len + 2));
        for (int i = 0; i < len; i += 2) dp[i][i].insert(s[i] - '0');
        
        // 区间dp
        for (int k = 2; k < len; k += 2) {
            for (int l = 0; l + k < len; l += 2) {
                for (int t = 0; t < k; t += 2) {
                    // 左边[l, l + t] 右边[l + t + 2, l + k]
                    for (auto x: dp[l][l + t]) for (auto y: dp[l + t + 2][l + k]) {
                        if (s[l + t + 1] == '+') {
                            if (x + y <= 1000) dp[l][l + k].insert(x + y);
                        } else {
                            if (x * y <= 1000) dp[l][l + k].insert(x * y);
                        }
                    }
                }
            }
        }
        
        for (auto x: dp[0][len - 1]) if (x != rightValue) ans += 2 * cnt[x];
        return ans;
    }
};
