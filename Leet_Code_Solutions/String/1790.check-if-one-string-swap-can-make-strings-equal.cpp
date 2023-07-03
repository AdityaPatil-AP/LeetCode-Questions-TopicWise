class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {

        // We have atmost one swap.
        // zero swap.
        if (s1 == s2)
        {
            return true;
        }

        // one swap.
        // means two indices have different characters.
        int firstIndex = -1;
        int secondIndex = -1;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                if (firstIndex == -1)
                {
                    firstIndex = i;
                }
                else if (secondIndex == -1)
                {
                    secondIndex = i;
                }
                else
                {
                    return false;
                }
            }
        }

        // If only one character is mismatched then it is impossible them to make
        // equal in one swap only.
        if (secondIndex == -1)
        {
            return false;
        }

        return (s1[firstIndex] == s2[secondIndex] && s1[secondIndex] == s2[firstIndex]);
    }
};