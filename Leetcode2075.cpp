class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int col = encodedText.size() / rows;
        string res;
        for (int y = 0; y < col; y++)
            for (int i = 0, j = y; i < rows && j < col; i++, j++)
                res += encodedText[i * col + j];

         res.erase(res.find_last_not_of(" ") + 1);
         return res;
    }
};
