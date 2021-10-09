class Solution {
public:

    bool check(vector<int> f) {
        //先取1
        //112121212...  也就是1(12)循环
        if (f[1] == 0) return false;
        f[1]--;
        
        // 3可以随便插入到任何一个非0的位置，不会改变前缀和的结果(%3意义下)
        int s = 1 + f[0];
        int x = min(f[1], f[2]);
        f[1] -= x, f[2] -= x;
        if (f[1]) s++, f[1]--;
        return s % 2 == 1 && (f[1] + f[2]);
    }
    
    
    bool stoneGameIX(vector<int>& stones) {
        vector<int> f(3);
        for (int x: stones) f[x % 3]++;
    
        
        //枚举先取1还是先取2
        return check({f[0], f[1], f[2]}) || check({f[0], f[2], f[1]});

        
    }
};
