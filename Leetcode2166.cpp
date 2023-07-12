class Bitset {
private:
    vector<int> arr;   // 存储每一位的数组
    int cnt = 0;   // 1 的个数
    int reversed = 0;   // 反转操作的次数奇偶性
public:
    Bitset(int size) {
        arr.resize(size);
        cnt = 0;
        reversed = 0;
    }
    
    void fix(int idx) {
        if ((arr[idx] ^ reversed) == 0) {
            arr[idx] ^= 1;
            ++cnt;
        }
    }
    
    void unfix(int idx) {
        if ((arr[idx] ^ reversed) == 1) {
            arr[idx] ^= 1;
            --cnt;
        }
    }
    
    void flip() {
        reversed ^= 1;
        cnt = arr.size() - cnt;
    }
    
    bool all() {
        return cnt == arr.size();
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string res;
        for (int bit: arr) {
            res.push_back('0' + (bit ^ reversed));
        }
        return res;
    }
};
