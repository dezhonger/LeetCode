public class Solution
{
    public int TimeRequiredToBuy(int[] tickets, int k)
    {
        int n = tickets.Length, t = 0;
        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                if (tickets[i] > 0)
                {
                    t++;
                    tickets[i]--;
                    if (tickets[k] == 0) return t;
                }
            }
        }
        return -1;
    }
}
