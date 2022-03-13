public class Solution
{
    private bool isVowel(char c)
        => ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
    public int CountVowelSubstrings(string word)
    {
        int result = 0;
        for (int i = 0; i < word.Length; i++)
        {
            var hash = new HashSet<char>();
            for (int j = i; j < word.Length; j++)
            {
                if (!isVowel(word[j])) break;
                hash.Add(word[j]);
                if (hash.Count == 5) result++;
            }
        }
        return result;
    }
}
