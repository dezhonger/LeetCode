class Solution:
    def capitalizeTitle(self, title: str) -> str:
        words = title.split()
        for i, l in enumerate(words):
            if (len(l)) <= 2:
                words[i] = l.lower()
            else :
                words[i] = l[0].upper() + l[1:].lower()
        return ' '.join(words);
