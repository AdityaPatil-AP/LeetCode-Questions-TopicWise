class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        // Net score should be maximum.
        sort(tokens.begin(), tokens.end());

        // From where I can lose -> starti.
        // From where I can gain -> endi.
        int ans = 0, curr = 0;
        int n = tokens.size();
        int starti = 0, endi = n - 1;

        while (true)
        {
            while (starti <= endi && power >= tokens[starti])
            {
                power -= tokens[starti++];
                curr++;
                ans = max(ans, curr);
            }

            if (starti > endi)
            {
                break;
            }

            power += tokens[endi--];
            curr--;

            if (curr < 0)
            {
                break;
            }
        }

        return ans;
    }
};