
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> res;
        for(int i = 1;; i++) {
            if (memory1 < i && memory2 < i) {
                res = {i, memory1, memory2};
                break;
            }
            if (memory1 >= i && memory2 >= i) {
                if (memory1 >= memory2) {
                    memory1 -= i;
                } else {
                    memory2 -= i;
                }
            } else if (memory1 >= i) memory1 -= i;
            else memory2 -= i;
        }
        return res;
    }
};
