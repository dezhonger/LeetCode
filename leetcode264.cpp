//建立一个ugly数组，每次从里面选择数分别乘以2、3、5.
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        int index3, index2, index5, a, b, c;
        index2 = index3 = index5 = 1;
        a = 2; b = 3; c = 5;
        for(int i = 1; i <= n; i++) {
            int mi = min(a, min(b, c));
            v.push_back(mi);
            if(a == mi) a = v[index2++] * 2;
            if(b == mi) b = v[index3++] * 3;
            if(c == mi) c = v[index5++] * 5;
        }
        return v[n-1];
    }
};