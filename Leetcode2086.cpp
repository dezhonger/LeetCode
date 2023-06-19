class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            if (hamsters[i] == 'H')
            {
                // Greedy strategy, priority to the right
                if (i + 1 < n && hamsters[i + 1] != 'H')
                {
                    i += 2;
                    res++;
                }
                else if (i > 0 && hamsters[i - 1] != 'H') res++;
                else return -1;
            }
        }
        return res;
    }
};
