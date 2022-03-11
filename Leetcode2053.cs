public class Solution
{
    public string KthDistinct(string[] arr, int k)
    {
        //var map = arr.GroupBy(a => a).ToDictionary(g => g.Key, g => g.Count());
        return arr
            .GroupBy(o => o)
            .Where(g => g.Count() == 1)
            .Skip(k - 1)
            .Select(g => g.Key)
            .DefaultIfEmpty("")
            .First();
    }
}
