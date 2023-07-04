class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), [](const auto& a, const auto& b){ return a[0] < b[0];});

        int n = tiles.size(), l = 0, r = 0, sum = 0, res = 0;
        while (l <= r && r < n)
        {
            int ll = tiles[l][0], rr = ll + carpetLen - 1;

            if (tiles[r][1] <= rr)  sum = sum + tiles[r][1] - tiles[r][0] + 1, r++, res = max(res, sum);
            else
            {
                if (rr >= tiles[r][0]) res = max(res, sum + rr - tiles[r][0] + 1);
                sum = sum - (tiles[l][1] - tiles[l][0] + 1);
                l++;
            }
        }
        return res;
    }
};
