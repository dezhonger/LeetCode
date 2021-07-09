
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n);
        int last = INT_MAX;
        stack<int> st;
        st.push(n - 1);
        ans[n - 1] = -1;
        
        for (int i = n - 2; i >= 0; i--) {
            while (st.size()) {
                // 如果当前车的速度比栈顶速度小 或
                // 当前车追上栈顶的车的时间要慢于栈顶车追上它后面的车的时间，那么栈顶的车就贡献了
                if (cars[i][1] <= cars[st.top()][1] ||
                    (ans[st.top()] > 0 && -1.0 * (cars[st.top()][0] - cars[i][0]) / (cars[st.top()][1] - cars[i][1]) > ans[st.top()])) {
                    st.pop();
                } else {
                    break;
                }
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = -1.0 * (cars[st.top()][0] - cars[i][0]) / (cars[st.top()][1] - cars[i][1]);
            }
            st.push(i);
        }
        return ans;
    }
};
