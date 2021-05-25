class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() && height[i] >= height[st.top()]) {
                int k = st.top();
                st.pop();
                if (st.empty()) break;
                ans += (i - st.top() - 1) * (min(height[i], height[st.top()]) - height[k]);
            }
            st.push(i);
        }
        return ans;
    }
};
