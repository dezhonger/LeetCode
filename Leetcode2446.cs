public class Solution {
    public bool HaveConflict(string[] event1, string[] event2)
    {
        return String.CompareOrdinal(event1[0], event2[1]) <= 0 && string.CompareOrdinal(event2[0], event1[1]) <= 0;
    }
}
