class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(begin(tokens), end(tokens));

        int max_score = 0;

        int curr_score = 0;

        int n = tokens.size();
        int j = n - 1;
        for (int i = 0; i <= j;)
        {
            if (power >= tokens[i])
            {
                curr_score++;
                max_score = max(max_score, curr_score);
                power -= tokens[i];
                i++;
            }
            else if (curr_score >= 1)
            {
                curr_score--;
                power += tokens[j--];
            }
            else
            {
                i++;
            }
        }

        return max_score;
    }
};