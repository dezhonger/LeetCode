class FrontMiddleBackQueue {
public:
    //为奇数的时候,d1.size() + 1 = d2.size()
    deque<int> d1, d2;
    FrontMiddleBackQueue() {
        d1.clear();
        d2.clear();
    }
    
    void adjust() {
        if (d1.size() + 2 == d2.size()) {
            int x = d2.front();
            d2.pop_front();
            d1.push_back(x);
        }
    }
    void adjust2() {
        if (d1.size() > d2.size()) {
            int x = d1.back();
            d1.pop_back();
            d2.push_front(x);
        }
    }
    
    void pushFront(int val) {
        d1.push_front(val);
        adjust2();
    }
    
    void pushMiddle(int x) {
        if (d1.size() == d2.size()) d2.push_front(x);
        else d1.push_back(x);
    }
    
    void pushBack(int val) {
        d2.push_back(val);
        adjust();
    }
    
    int popFront() {
        if (d1.size() + d2.size() == 0) return -1;
        if (d1.size() == 0) {
            int x = d2.front();
            d2.pop_front();
            return x;
        } else {
            int x = d1.front();
            d1.pop_front();
            adjust();
            return x;
        }
    }
    
    int popMiddle() {
        if (d1.size() + d2.size() == 0) return -1;
        if (d1.size() + 1 == d2.size()) {
            int x = d2.front();
            d2.pop_front();
            return x;
        } else {
            int x = d1.back();
            d1.pop_back();
            return x;
        }
    }
    
    int popBack() {
        if (d1.size() + d2.size() == 0) return -1;
        int x = d2.back();
        d2.pop_back();
        adjust2();
        return x;
    }
};
