class Solution
{
public:
    string largestMerge(string word1, string word2)
    {
        // Lexicographically larger : The first position where string a and b differ.
        // a has higher character than b.

        int i = 0, j = 0; // i -> pointer to a.
        // j -> pointer to b.
        int n = word1.size();
        int m = word2.size();

        string ans = "";

        while (i < n && j < m)
        {
            // If the two characters to be checked are different then,
            // we can directly insert them into the answer array.

            if (word1[i] > word2[j])
            {
                ans += word1[i++];
            }
            else if (word1[i] < word2[j])
            {
                ans += word2[j++];
            }
            else
            {
                // But if they are same, we have to look for the first position
                // later to these current positions, where they differ and choose the
                // string which has lexicographically bigger character.

                string s = word1.substr(i + 1);
                string t = word2.substr(j + 1);

                if (s > t)
                    ans += word1[i++];
                else
                    ans += word2[j++];
            }
        }

        while (i < n)
            ans += word1[i++];
        while (j < m)
            ans += word2[j++];

        return ans;
    }
};