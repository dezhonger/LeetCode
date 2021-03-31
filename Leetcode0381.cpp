class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> h;
    vector<int> nums;
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = h[val].empty();
        h[val].insert(nums.size());
        nums.push_back(val);
        return res;
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        //注意分析只有一个元素的情况，以及要删除的元素和数组最后一个值是相同值的情况
        if (h[val].empty()) return false;
        int idx = *h[val].begin();
        int bidx = nums.size() - 1;
        int x = nums[bidx];
        swap(nums[idx], nums[bidx]);
        h[val].erase(idx);
        //这句加上也没有问题
        //h[val].insert(bidx);
        h[x].erase(bidx);
        h[x].insert(idx);
        nums.pop_back();
        //这个去掉就错了
        h[val].erase(bidx);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */