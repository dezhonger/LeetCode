public class Solution
{
    public bool CheckAlmostEquivalent(string word1, string word2)
    {
        var dict = word1.GroupBy(o => o).ToDictionary(o => o.Key, o => o.Count());
        foreach (char c in word2)
        {
            if (dict.ContainsKey(c)) dict[c]--;
            else dict.Add(c, -1);
        }
        return dict.All(v => (Math.Abs(v.Value) <= 3));
        
        // the below is both right.
        // return dict.Max(o=> Math.Abs(o.Value)) <= 3;
        // return !dictionary.Any(i => Math.Abs(i.Value) > 3);
        
    }
}
