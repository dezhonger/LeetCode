class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = h.size();
        stack<int> s;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int v = h[i];
            if (s.empty()) s.push(i);
            else {
                while (s.size() && v > h[s.top()]) {
                    int c = s.top();
                    res[c]++;
                    s.pop();
                }
                if (s.size()) res[s.top()]++;
                s.push(i);
            }
            
        }
        return res;
    }
};
