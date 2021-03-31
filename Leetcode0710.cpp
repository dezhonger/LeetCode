class Solution {
public:
    int n, len;
    unordered_map<int, int> h;
    unordered_set<int> s;
    Solution(int _n, vector<int>& blacklist) {
        n = _n;
        len = blacklist.size();
        for (int i = n - len; i < n; i++) s.insert(i);
        for (int x : blacklist) s.erase(x);
        //s存储的是所有>=n-len内的白名单的元素，也就是可以被选到的
        //然后我们对在[0, n - len)内的黑名单值映射到一个白名单
        auto it = s.begin();
        for (int x : blacklist) {
            if (x < n - len) h[x] = *it++;
        }
    }
    
    int pick() {
        int x = rand() % (n - len);
        if (h.count(x)) return h[x];
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */