#include <iostream>

using namespace std;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int N = 1702766719;
int guess(int num){
    if(num > N) return -1;
    else if(num < N) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int c = 1;
        int l = 1, r = n;
        while(1) {
            int mid = l + (r - l) / 2;
            cout << mid << endl;
            int tmp = guess(mid);
            if(tmp == 0) return mid;
            if(tmp > 0) l = mid + 1;
            else r = mid - 1;
        }
    }
};

int main()
{
    Solution s;
    cout << s.guessNumber(2126753390);
    return 0;
}
