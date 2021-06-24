class Solution {
public:
    string maximumBinaryString(string binary) {
        int z = 0, n = binary.size();
        
        int k = 0;
        while (k < n && binary[k] == '1') k++;
        string res(k, '1');
        for (int i = k; i < n; i++) {
            if (binary[i] == '0') z++;
        }
        for (int i = 0; i < z - 1; i++) res += '1';
        if (z) res += '0';
        for (int i = 0; i < n - k - z; i++) res += '1';
        return res;
    }
};
