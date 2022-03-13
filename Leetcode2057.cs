public class Solution
{
    public int SmallestEqual(int[] nums)
    {
        return nums
            .Select((number, index) => (number, index))
            .Where(o => o.number == (o.index % 10))
            .Select(o => o.index)
            .DefaultIfEmpty(-1)
            .First();
    }
}
