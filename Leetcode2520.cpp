class Solution {
public:
    int countDigits(int num) {
        int x = num, res = 0;
        while (num)
        {
            if (x % (num % 10) == 0) res++;
            num /= 10;
        }
        
        return res;
    }
};
