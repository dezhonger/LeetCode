  public class Solution
  {
      public int CountValidWords(string sentence)
          => sentence
              .Split(' ', StringSplitOptions.RemoveEmptyEntries)
              .Count(o => IsValidToken(o));

      private bool IsValidToken(string token)
      {
          int hyphenCount = 0;
          int punctuationCount = 0;
          for (int i = 0; i < token.Length; i++)
          {
              if (char.IsDigit(token[i])) return false;
              else if (IsHyphen(token[i]))
              {
                  hyphenCount++;
                  if (hyphenCount > 1 || !IsValidHyphen(token, i)) return false;
              }
              else if (IsPunctuationMark(token[i]))
              {
                  punctuationCount++;
                  if (punctuationCount > 1 || !IsValidPunctuation(token, i))
                  {
                      return false;
                  }
              }
          }
          return true;
      }

      private readonly char[] PunctuationMarks = new char[] { '!', '.', ',' };
      private bool IsPunctuationMark(char symbol) => PunctuationMarks.Contains(symbol);
      private bool IsHyphen(char symbol) => symbol == '-';
      private bool IsValidPunctuation(string token, int punctuationIndex)
          => punctuationIndex == token.Length - 1;
      private bool IsValidHyphen(string token, int hyphenIndex)
          => hyphenIndex != 0 && hyphenIndex != token.Length - 1 
              && Char.IsLower(token[hyphenIndex - 1])
              && Char.IsLower(token[hyphenIndex + 1]);

  }
