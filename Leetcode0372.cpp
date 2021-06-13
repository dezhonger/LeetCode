#include <iostream>
#include <vector>
using namespace std;

题目中b以十进制的方式表示出来。
举例说明a, b = 573
b[] = [5,7,3]
a^b = a^500 * a^70 * a^3
    = a^3 * (a^10)^7 * (a^100)^5

class Solution {
public:
    int qp(int a, int b) {
        int ans = 1, mod = 1337;
        while(b) {
            if(b & 1) ans =  ans * a;
            a = a * a;
            a %= mod;
            b >>= 1;
        }
        return ans % mod;
    }
    int superPow(int a, vector<int>& b) {
        a %= 1337;
        int ans = 1, c = a, mod = 1337;
        for(int i = b.size() - 1; i >= 0; i--) {
            ans = ans * qp(c, b[i]);
            ans %= mod;
            c = qp(c, 10);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
