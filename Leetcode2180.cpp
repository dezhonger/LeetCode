class Solution {
public:
    bool evenSum(int x)
    {
        int res = 0;
        while (x)
        {
            res += x % 10;
            x /= 10;
        }

        return res % 2 == 0;
    }

    int countEven(int num) {
        int res = 0;

        for (int i = 2; i <= num; i++)
        {
            if (evenSum(i)) res++;
        }

        return res;
    }
};
