
class Solution {
public:
    stack<vector<int>> nums;
    stack<char> op;
    
    int get_min(vector<int> x) {
        int r = INT_MAX;
        for (int y : x) r = min(y, r);
        return r;
    }
    
    void eval() {
        vector<int> n1 = nums.top();
        nums.pop();
        vector<int> n2 = nums.top();
        nums.pop();
        vector<int> n3(2);
        char c = op.top();
        op.pop();
        if (c == '&') {
            //&的时候两个至少一个为0. 或者改变符号，且两个数字都是0
            int a0 = get_min({n1[0] + n2[1], n1[1] + n2[0], n1[0] + n2[0], n1[0] + n2[0] + 1});
            int a1 = get_min({n1[1] + n2[1], n1[1] + n2[0] + 1, n1[0] + n2[1] + 1, n1[1] + n2[1] + 1});
            nums.push({a0, a1});
        } else {
            int b0 = get_min({n1[0] + n2[1] + 1, n1[1] + n2[0] + 1, n1[0] + n2[0] + 1, n1[0] + n2[0]});
            int b1 = get_min({n1[1] + n2[1], n1[1] + n2[0], n1[0] + n2[1], n1[1] + n2[1] + 1});
            nums.push({b0, b1});
        }
    }

    int minOperationsToFlip(string expression) {
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (isdigit(c)) {
                if (c == '1') nums.push({1, 0});
                else nums.push({0, 1});
            } else if (c == '(') {
                op.push(c);
            } else if (c == ')') {
                while (op.top() != '(') eval();
                op.pop();
            } else {
                if (op.size() && op.top() != '(') {
                    //存在一个&或者|, 就计算一下
                    eval();
                }
                op.push(c);
            }
        }
        while (op.size()) eval();
        auto res = nums.top();
        //至少一个是0，也就是原表达式额度值。我们需要的是变成另外一个值的最少操作次数
        return max(res[0], res[1]);
    }
};
