class Solution {
public:
    int n;
        
    bool check(string& a, string& b) {
        vector<char> c(n);
        for (int i = 1; i <= n; i++) c[i - 1] = a[i];
        
        //需要满足k个匹配的才是回文串
        int k = n / 2, s = 0;
        for (int i = 0, j = c.size() - 1; i < j; i++, j--) {
            if (c[i] == c[j]) s++;
        }
        //从0开始分隔就是回文串
        if (s == k) return true;
        
        //每次移动分隔点一位，判断去掉的和加入的是否匹配
        for (int i = n - 1, j = n; i >= 0; i--, j--) {
            // 和i匹配的下标是 n - 1 - i
            s -= (c[i] == c[n - 1 - i]);
            c[i] = b[j];
            s += (c[i] == c[n - 1 - i]);
            if (s == k) return true;
        }
        return false;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        this -> n = a.size();
        a = ' ' + a;
        b = ' ' + b;
        return check(a, b) || check(b, a);
    }
};
