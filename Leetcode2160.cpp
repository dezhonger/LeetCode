class Solution {
public:
    int minimumSum(int num) {
        vector<int> v(4);
        v[0] = num % 10;
        v[1] = (num / 10) % 10;
        v[2] = (num / 100) % 10;
        v[3] = num / 1000;
        sort(v.begin(), v.end());
        int res = 10000;
        do
        {
            int t = (10 * v[0] + v[1]) + (10 *  v[2] + v[3]);
            res = min(res, t);
        } while(next_permutation(v.begin(), v.end()));  

        return res;
        
    }
};
