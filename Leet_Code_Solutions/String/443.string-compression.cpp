class Solution
{
public:
    int compress(vector<char> &chars)
    {
        // we don't have to create the string we just have to store the lengths.

        int freq = 1;
        char m = chars[0];
        int ans = 0;
        int j = 0; // for modifying the input array.
        for (int i = 1; i < chars.size(); i++)
        {
            if (m == chars[i])
            {
                freq++;
            }
            else
            {
                if (freq == 1)
                {
                    ans += 1;
                    chars[j++] = m;
                }
                else
                {
                    string number = to_string(freq);
                    ans += (1 + number.size());
                    chars[j++] = m;
                    for (int k = 0; k < number.size(); k++)
                    {
                        chars[j++] = number[k];
                    }
                }
                m = chars[i];
                freq = 1;
            }
        }
        if (freq == 1)
        {
            ans += 1;
            chars[j++] = m;
        }
        else
        {
            string number = to_string(freq);
            ans += (1 + number.size());
            chars[j++] = m;
            for (int k = 0; k < number.size(); k++)
            {
                chars[j++] = number[k];
            }
        }

        return ans;
    }
};