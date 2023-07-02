class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // if size of word is less than 2. then it is always true.
        if (word.size() < 2)
            return true;
        // three usages are allowed.
        // 1) All capital letters.
        // if my first letter is capital and then the second letter is capital then the capital should have every
        // character as uppercase.
        // 2) all lowercase letters.
        // 3) only first letter is capital.
        if (isUpper(word[0]) && isUpper(word[1]))
        {
            for (int i = 2; i < word.size(); i++)
            {
                if (isLower(word[i]))
                    return false;
            }
        }
        else
        {
            for (int i = 1; i < word.size(); i++)
            {
                if (isUpper(word[i]))
                    return false;
            }
        }
        return true;
    }

private:
    bool isUpper(char m)
    {
        return (m >= 'A' && m <= 'Z');
    }

    bool isLower(char m)
    {
        return (m >= 'a' && m <= 'z');
    }
};
