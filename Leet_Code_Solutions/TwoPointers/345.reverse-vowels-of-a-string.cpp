class Solution
{
public:
    // Return true if the character is a vowel (case-insensitive)
    bool checkVowel(char c)
    {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u' || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i <= j)
        {
            while (i <= j && !checkVowel(s[i]))
            {
                i++;
            }
            while (i <= j && !checkVowel(s[j]))
            {
                j--;
            }
            if (i <= j)
            {
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
};