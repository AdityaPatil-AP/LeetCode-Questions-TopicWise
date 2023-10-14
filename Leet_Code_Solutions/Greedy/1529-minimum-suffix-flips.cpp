class Solution
{
public:
    int minFlips(string target)
    {
        // Minimum Suffix flips.
        // Initially the string is :
        // "0000" of target size.

        int n = target.size();

        int flipCount = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            char curr = '0' + flipCount % 2;
            if (target[i] == curr)
            {
                continue;
            }
            else
            {
                flipCount++;
                ans++;
            }
        }

        return ans;
    }
};