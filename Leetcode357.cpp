#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10) n = 10;
        int ans[11], r = 0;
        ans[0] = 1, ans[1] = 9, ans[2] = 81;
        for(int i = 3; i <= n; i++) {
            ans[i] = ans[i - 1] * (9 - i + 2);
        }
        for(int i = 0; i <= n; i++) r += ans[i];
        return r;

    }
};

int main()
{
    Solution s;
//    cout << s.dd();
    cout << s.countNumbersWithUniqueDigits(3) << endl;;
//    s.print();
    return 0;
}
