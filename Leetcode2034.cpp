
class StockPrice {
public:
    unordered_map<int, int> mp;
    multiset<int> ms;
    int c = 0;
    StockPrice() {
        mp.clear();
        ms.clear();
    }
    
    void update(int timestamp, int price) {
        if (mp.count(timestamp)) {
            int old = mp[timestamp];
            ms.erase(ms.find(old));
            mp[timestamp] = price;
            ms.insert(price);
        } else {
            mp[timestamp] = price;
            ms.insert(price);
        }
        c = max(c, timestamp);
    }
    
    int current() {
        return mp[c];
    }
    
    int maximum() {
        return *ms.rbegin();
    }
    
    int minimum() {
        return *ms.begin();
    }
};
