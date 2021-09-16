
class Solution {
public:
    unordered_set<string> append(unordered_set<string> S, char c) {
        unordered_set<string> T;
        for (auto s: S) {
            s.push_back(c);
            T.insert(s);
        }
        return T;
    }

    unordered_set<string> mul(unordered_set<string> A, unordered_set<string> B) {
        unordered_set<string> C;
        for (auto a: A) for (auto b : B) C.insert(a + b);
        return C;
    }

    unordered_set<string> add(unordered_set<string> A, unordered_set<string> B) {
        for (auto b: B) A.insert(b);
        return A;
    }

    unordered_set<string> dfs(string& e, int& L) {
        unordered_set<string> ans;
        unordered_set<string> cur = {""};
        while (L < e.size()) {
            if (e[L] == ' ') {
                L++;
                continue;
            }

            if (e[L] == '{') {
                L++;
                cur = mul(cur, dfs(e, L));
            } else if (e[L] == ',') {
                ans = add(ans, cur);
                cur = {""};
                L++;
            } else if (e[L] == '}') {
                ans = add(ans, cur);
                L++;
                return ans;
            } else {
                cur = append(cur, e[L]);
                L++;
            }
        }
        ans = add(ans, cur);
        return ans;
    }





    vector<string> braceExpansionII(string expression) {
        int L = 0;
        auto t = dfs(expression, L);
        vector<string> res(t.begin(), t.end());
        sort(res.begin(), res.end());
        return res;
    }
};

