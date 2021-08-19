//二进制最高位1的位置 输入5得出2
unsigned msb(unsigned x) {
    return 31 - __builtin_clz(x);
}
class Solution {
public:
    int cal(int n) {
        if (n <= 1) return n;
        int t1 = 1 << msb(n), t2 = n - t1;
        //n是2的幂
        if (t2 == 0) return 2 * cal(t1 / 2) + 1;
        return cal(t1) - cal(t2);
        
    }

    int minimumOneBitOperations(int n) {
        return cal(n);
    }
};
