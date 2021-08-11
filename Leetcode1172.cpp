//可用树状数组加二分解，常数更小
class DinnerPlates {
public:
    int sz, c;
    // 没有满的栈
    set<int> nfull;
    // 非空的栈
    set<int> nempty;
    stack<int> st[150005];
    DinnerPlates(int capacity) {
        sz = -1;
        this -> c = capacity;
        nfull = set<int>();
        nempty = set<int>();
    }
    
    void push(int val) {
        if (nfull.size() == 0) {
            nfull.insert(++sz);
        }
        
        int idx = *nfull.begin();
        st[idx].push(val);
        nempty.insert(idx);
        
        if (st[idx].size() == c) nfull.erase(idx);
    }
    
    int pop() {
        if (nempty.size() == 0) return -1;
        int idx = *nempty.rbegin();
        int ans = st[idx].top();
        st[idx].pop();
        if (st[idx].size() == 0) nempty.erase(idx);
        nfull.insert(idx);
        return ans;
    }
    
    int popAtStack(int idx) {
        if (st[idx].size() == 0) return -1;
        int ans = st[idx].top();
        st[idx].pop();
        if (st[idx].size() == 0) nempty.erase(idx);
        nfull.insert(idx);
        return ans;
    }
};
