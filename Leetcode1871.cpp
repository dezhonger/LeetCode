const int N = 100010;

class Solution {
public:
    int tr[N];
    int n;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    void add(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) tr[i] += x;
    }
    
    int sum(int pos) {
        int res = 0;
        for (int i = pos; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
    
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    // i + minJump <= j <= min(i + maxJump, s.length - 1)
    // j - maxJump <= i <= j - minJump
    

    bool canReach(string s, int minJump, int maxJump) {
        n = s.size();
        if (s.back() != '0') return false;
        add(1, 1);
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '1') continue;
            int l = max(1, i - maxJump), r = i - minJump;
            if (r <= 0) continue;
            if (sum(l, r) > 0) add(i, 1);
        }
        return sum(n, n) > 0;
    }
};
