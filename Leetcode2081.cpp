typedef long long LL;


vector<int> d(100);
class Solution {


public:

    bool isPalindrome(LL x, int k = 10) {
        int c = 0;
        while (x) {
            d[c++] = x % k;
            x /= k;
        }
        //debug(y, k, d);
        for (int i = 0, j = c - 1; i < j; i++, j--) {
            if (d[i] != d[j]) return false;
        }
        return true;
        
    }
    long long kMirror(int k, int n) {
        int left = 1, count = 0;
        LL ans = 0;
        while (count < n) {
            int right = left * 10;
            
            {
                for (int i = left; i < right && count < n; i++) {
                    //奇数位数
                    LL c = i;
                    int d = i / 10;
                    while (d) c = c * 10 + d % 10, d /= 10;
                    if (isPalindrome(c) && isPalindrome(c, k)) count++, ans += c;
                }
                
            }
            
            {
                for (int i = left; i < right && count < n; i++) {
                     //偶数位数
                    LL c = i;
                    int d = i;
                    while (d) c = c * 10 + d % 10, d /= 10;
                    if (isPalindrome(c) && isPalindrome(c, k))  count++, ans += c;
                }
                
            }
            left = right;
        }
        return ans;
    }
};
