class Solution {
public:
    int p[27]; 

    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int a, int b)
    {
        int aa = find(a);
        int bb = find(b);
        p[max(aa, bb)] = min(aa, bb);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        for (int i = 0; i < 26; i++) p[i] = i;
        for (int i = 0; i < s1.size(); i++) merge(s1[i] - 'a', s2[i] - 'a');
        for (int i = 0; i < baseStr.size(); i++) baseStr[i] = find(baseStr[i] - 'a') + 'a';
        return baseStr;
    }
};
