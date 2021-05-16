class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> S(bank.begin(), bank.end());
        unordered_map<string, int> dist;
        queue<string> q;
        dist[start] = 0;
        q.push(start);
        string ch = "AGCT";
        while (q.size()) {
            string s = q.front();
            q.pop();
            for (int i = 0; i < (int)s.size(); i++) {
                string t = s;
                for (char c : ch) {
                    t[i] = c;
                    if (c != s[i] && dist[t] == 0 && S.find(t) != S.end()) {
                        dist[t] = dist[s] + 1;
                        if (t == end) return dist[t];
                        q.push(t);
                    }
                }
            }
        }
        return -1;
    }
};
