class Solution {
    public int prefixCount(String[] words, String pref) {
        int res = 0;
        for (String w: words)
        {
            if (w.startsWith(pref)) res++;
        }

        return res;
    }
}
