class Solution {
public:
    int trap(vector<int>& h) {
        int res = 0, n = h.size();
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            int last = 0;
            while (s.size() && h[i] >= h[s.top()]) {
                res += (h[s.top()] - last) * (i - s.top() - 1);
                last = h[s.top()];
                s.pop();
            }
            if (s.size()) res += (i - s.top() - 1) * (h[i] - last);
            s.push(i);

        }
        return res;
    }
};

