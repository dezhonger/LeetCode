const int N = 19997;

class MyHashSet {
public:
    vector<int> h[N];
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    int find(vector<int> h, int val) {
        int n = h.size();
        for (int i = 0; i < n; i++) {
            if (h[i] == val) return i;
        }
        return -1;
    }
    
    void add(int key) {
        int t = key % N;
        if (find(h[t], key) == -1) h[t].push_back(key);
    }
    
    void remove(int key) {
        int t = key % N;
        int pos = find(h[t], key);
        if (pos != -1) {
            h[t].erase(h[t].begin() + pos);
        }
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int t = key % N;
        return find(h[t], key) != -1;
    }
};
