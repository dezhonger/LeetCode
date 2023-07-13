class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans = 0;
        stack<pair<int, int>> st;
        for (int x : nums)
        {
            int maxT = 0;
            while (!st.empty() && st.top().first <= x)
            {
                maxT = max(maxT, st.top().second);
                st.pop();
            }

            maxT = st.empty() ? 0 : maxT + 1;
            ans = max(ans, maxT);
            st.push(make_pair(x, maxT));

            // cout << x << " " << maxT << endl;
        }
        return ans;
    }
};
